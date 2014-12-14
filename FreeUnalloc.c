#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//5: Freeing a block not allocated before
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	void* testVariable1;
	testVariable1 = (int*)malloc(100);
	free(testVariable1 - (char)100);
	return 1;
};
//Output is super
// Allocating variable with ID: 0 0x100637070
// ERROR: You tried to free an address that was not allocated
// Memory entry of length	100	leaked: 0x100637070
// 	Was declared in 'main.c' on line 8