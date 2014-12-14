#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMalloc.c"

//9: Realloc
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
//Output rules
// 	     _[_]_
//       (")
//   `--( : )--'
//     (  :  )

//  0x10f322080
// before: 100
//  0x10f322114
// ID: 0 freeing 0x10f322080
// ID: 0 freed
// after: 200
// Memory entry of length	200	leaked: 0x10f322114
// 	Was declared in 'main.c' on line 11