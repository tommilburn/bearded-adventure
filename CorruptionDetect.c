#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//7: Corruption detection
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	char* tester  = (char*)malloc(100);
	char* tester2 = (char*)malloc(200);
	memset(tester2 - sizeof(struct MemEntry) + 1, 0, sizeof(struct MemEntry) - 1);
	char* tester3 = (char*)malloc(300);
	free(tester);
	free(tester2);
	free(tester3);
	return 1;
};
//output is good! Bad good, but still good.
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )

//  0x107b51080
//  0x107b51114
// Super error! Someone borked the internal memory structure. Exiting...
// Memory entry of length	100	leaked: 0x107b51080
// 	Was declared in 'main.c' on line 8