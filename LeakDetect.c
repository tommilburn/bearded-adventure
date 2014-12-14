#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//EXTRA CREDIT
//6: Leak detection and reporting
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	void* testVariable1;
	testVariable1 = (int*)malloc(100);
	testVariable1 = (int*)malloc(400);
	testVariable1 = (int*)malloc(500);
	testVariable1 = (int*)malloc(600);
};
//Output is all good.
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )
// Allocating variable with ID: 0 0x1036b9070
// Allocating variable with ID: 1 0x1036b9104
// Allocating variable with ID: 2 0x1036b92c4
// Allocating variable with ID: 3 0x1036b94e8
// Memory entry of length	100	leaked: 0x1036b9070
// 	Was declared in 'main.c' on line 8
// Memory entry of length	400	leaked: 0x1036b9104
// 	Was declared in 'main.c' on line 9
// Memory entry of length	500	leaked: 0x1036b92c4
// 	Was declared in 'main.c' on line 10
// Memory entry of length	600	leaked: 0x1036b94e8
// 	Was declared in 'main.c' on line 11