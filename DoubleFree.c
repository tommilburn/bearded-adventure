#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//4: Freeing a block that has already been freed
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	void* testVariable1;
	testVariable1 = (int*)malloc(100);
	free(testVariable1);
	free(testVariable1);
	return 1;
};
//Output is what we expected
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )
// Allocating variable with ID: 0 0x102dbb070
// ID: 0 freeing 0x102dbb070
// ID: 0 freed
// ID: 0 freeing 0x102dbb070
// ID: 0 ERROR: You tried to free an allocation that was already free