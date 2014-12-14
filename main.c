#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.c"
#include <string.h>

int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	char* testVariable1 = calloc(100);
	struct MemEntry *oldEntry = (struct MemEntry *)((char *)testVariable1 - sizeof(struct MemEntry));
	printf("before: %d\n", oldEntry->size);
	testVariable1 = realloc(testVariable1, 200);
	struct MemEntry *newEntry = (struct MemEntry *)((char *)testVariable1 - sizeof(struct MemEntry));

	printf("after: %d\n", newEntry->size);
	return 1;
};