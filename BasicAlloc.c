#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//1: Basic variable allocation:
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	void* testVariable1;
	testVariable1 = (int*)malloc(100);
	free(testVariable1);
	return 1;
};
//output is all good
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )
// Allocating variable with ID: 0 0x10bdc0070
// ID: 0 free attempt 0x10bdc0070
// ID: 0 freed