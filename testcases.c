/* Test cases */

//all files included:
#include <stdio.h>
#include <stdlib.h>
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



//8: Calloc
int main(){
	printf("     _[_]_\n      (\")\n  `--( : )--'\n    (  :  )\n\n");
	char* testVariable1 = calloc(100);
	for(int i = 0; i<100; i++){
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