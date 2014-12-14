#include <stdio.h>
#include <string.h>

#ifndef malloc_h
#define malloc_h

//seasonal printfs
#define CHRISTMAS     "\x1b[31m"
#define MORE_CHRISTMAS   "\x1b[32m"

struct MemEntry {
	unsigned int id;
	struct MemEntry	*prev, *succ;
	int		isfree : 2;
	int		size : 24;
	char *file;
	unsigned int line:18;
	int recognition;
};

char* christmas();
void *		my_malloc( unsigned int, char*, unsigned int);
void		my_free( void *, char*, unsigned int);
void		leak_check();
void *		my_calloc(unsigned int, char*, unsigned int);
int		valid_check(struct MemEntry*);
#define malloc(x) my_malloc(x, __FILE__, __LINE__);
#define free(x) my_free(x, __FILE__, __LINE__);
#define calloc(x) my_calloc(x, __FILE__, __LINE__);
#define realloc(X,Y) my_realloc(X, Y, __FILE__, __LINE__);
#endif
