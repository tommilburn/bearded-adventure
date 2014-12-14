#include	<stdio.h>
#include	"myMalloc.h"

// A toy malloc() implementation.  Introduction to malloc() internals.  See malloc2.c for a better version.

#define BLOCKSIZE	100000
#define RECOGNITION 0xbada55
int christmasCounter = 0;
int mallocCounter = 0;
static int	initialized = 0;
static char	big_block[BLOCKSIZE];


void * my_malloc( unsigned int size, char *file, unsigned int line )
{
	static struct MemEntry *	root;
	struct MemEntry *		p;
	struct MemEntry *		succ;
	// printf("%sAllocating variable with ID: %d", christmas(), mallocCounter);
	if ( !initialized )
	{
		root = (struct MemEntry *)big_block;
		root->prev = root->succ = 0;
		root->file = file;
		root->size = BLOCKSIZE - sizeof(struct MemEntry);
		root->isfree = 1;
		root->recognition = RECOGNITION;
		initialized = 1;
		atexit(leak_check);
	}
	p = root;
	do {
		if(p->succ != 0 && valid_check(p->succ) == 0){
			printf("Super error! Someone borked the internal memory structure. Exiting...\n");
			exit(1);
		}
		if ( p->size < size ){		//too small
			p = p->succ;	
		}
		else if ( !p->isfree ){		//already in use
			p = p->succ;					
		}
		else if ( p->size < (size + sizeof(struct MemEntry)) ){	//existing memEntry struct you can use!
			p->isfree = 0;					
			return (char *)p + sizeof(struct MemEntry);
		}
		else{	//need to make a new one!
			succ = (struct MemEntry *)((char *)p + sizeof(struct MemEntry) + size);
			succ->prev = p;
			succ->recognition = RECOGNITION;
			succ->succ = p->succ;
			if( p->succ != 0 ) p->succ->prev = succ;
			p->succ = succ;
			p->recognition = RECOGNITION;
			p->file = file;
			p->line = line;
			p->id = mallocCounter;
			mallocCounter++;
			succ->size = p->size - sizeof(struct MemEntry) - size;
			succ->isfree = 1;
			p->size = size;
			p->isfree = 0;
			printf(" %p\n", (char *)p + sizeof(struct MemEntry));
			return (char *)p + sizeof(struct MemEntry);
		}
	} while ( p != 0 );
	printf("Out of memory! Cannot allocate from %s on line %d\n", file, line);
	return 0;
}

void* my_calloc(unsigned int size, char *file, unsigned int line ){
	void *ptr = my_malloc(size, file, line);
	memset(ptr, 0, size);
	return ptr;
}
void* my_realloc(void *ptr, unsigned int newSize, char *file, unsigned int line ){
	struct MemEntry *oldEntry = (struct MemEntry *)((char *)ptr - sizeof(struct MemEntry));
	void *new = my_malloc(newSize, file, line);
	memcpy(new, ptr, oldEntry->size);
	free(ptr);
	return new;
}
void my_free( void * p, char* file, unsigned int line)
{
	struct MemEntry *		ptr;
	struct MemEntry *		pred;
	struct MemEntry *		succ;

	ptr = (struct MemEntry *)((char *)p - sizeof(struct MemEntry));
	if(valid_check(ptr) == 1){
		printf("%sID: %d freeing %p\n", christmas(), ptr->id, p);
		if(ptr->isfree == 0){
			if ( (pred = ptr->prev) != 0 && pred->isfree ){
				pred->size += sizeof(struct MemEntry) + ptr->size;	// merge with predecessor
				pred->succ = ptr->succ;
				ptr->recognition = 0;
				if ( ptr->succ != 0 ){
					ptr->succ->prev = pred;
				}			
			}
			else{
				printf("%sID: %d freed\n", christmas(), ptr->id);
				ptr->isfree = 1;
				pred = ptr;
			}
			if ( (succ = ptr->succ) != 0 && succ->isfree ){
				pred->size += sizeof(struct MemEntry) + succ->size;	// merge with successor
				pred->succ = succ->succ;
				succ->recognition = 0;
				if ( succ->succ != 0 ){
					succ->succ->prev = pred;
				}
			}
		} else {
			printf("%sID: %d ERROR: You tried to free an allocation that was already free\n", christmas(), ptr->id);
		}
	} else {
		printf("%sERROR: You tried to free an address that was not allocated\n", christmas());
		return;
	}
}

void leak_check(){
	struct MemEntry* ptr;
	for(ptr = (struct MemEntry *)big_block; ptr->succ != 0; ptr = ptr->succ){
		if(ptr->isfree == 0){
			printf("%sMemory entry of length\t%d\tleaked: %p\n", christmas(), ptr->size, (char*)ptr+sizeof(struct MemEntry));
			printf("%s\tWas declared in '%s' on line %d\n", christmas(), ptr->file, ptr->line);
		}
	}
}

int valid_check(struct MemEntry * ptr){
	if(ptr->recognition == RECOGNITION){
		return 1;
	} else {
		return 0;
	}
}

char * christmas(){
	christmasCounter++;
	if(christmasCounter % 2 == 0){
		return CHRISTMAS;
	} else {
		return MORE_CHRISTMAS;
	}
}


