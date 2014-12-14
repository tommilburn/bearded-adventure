#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//8: Calloc
int main(){
	int i;
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	char* testVariable1 = calloc(100);
	for(i = 0; i<100; i++){
		printf("%d", *(testVariable1 + i));
	}
	return 1;
};
//Output is boring
//      _[_]_
//       (")
//   `--( : )--'
//     (  :  )

//  0x10f34d080
// 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000Memory entry of length	100	leaked: 0x10f34d080
// 	Was declared in 'main.c' on line 8