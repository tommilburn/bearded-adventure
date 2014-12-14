#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//3: Allocation of different sizes
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	void* testVariable1;
	testVariable1 = (int*)malloc(100);
	void* testVariable2;
	testVariable2 = (int*)malloc(200);
	void* testVariable3;
	testVariable3 = (int*)malloc(300);	
	void* testVariable4;
	testVariable4 = (int*)malloc(400);

	free(testVariable1);
	free(testVariable2);
	free(testVariable3);
	free(testVariable4);
	return 1;
};
//output looks good
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )

// Allocating variable with ID: 0 0x100c25070
// Allocating variable with ID: 1 0x100c25104
// Allocating variable with ID: 2 0x100c251fc
// Allocating variable with ID: 3 0x100c25358
// ID: 0 freeing 0x100c25070
// ID: 0 freed
// ID: 1 freeing 0x100c25104
// ID: 2 freeing 0x100c251fc
// ID: 3 freeing 0x100c25358