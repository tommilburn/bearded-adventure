#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//2: Repeated allocation and freeing
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	void* testVariable1;
	testVariable1 = (int*)malloc(100);
	free(testVariable1);
	testVariable1 = (int*)malloc(100);
	free(testVariable1);
	testVariable1 = (int*)malloc(100);
	free(testVariable1);
	testVariable1 = (int*)malloc(100);
	free(testVariable1);		
	return 1;
};
//output is good
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )
// Allocating variable with ID: 0 0x10a271070
// ID: 0 free attempt 0x10a271070
// ID: 0 freed
// Allocating variable with ID: 1 0x10a271070
// ID: 1 free attempt 0x10a271070
// ID: 1 freed
// Allocating variable with ID: 2 0x10a271070
// ID: 2 free attempt 0x10a271070
// ID: 2 freed
// Allocating variable with ID: 3 0x10a271070
// ID: 3 free attempt 0x10a271070
// ID: 3 freed