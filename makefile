CFLAGS= -o

all:	BasicAlloc Calloc DoubleFree FreeUnalloc LeakDetect Realloc RepeatedAlloc VarySizesAlloc

BasicAlloc:
	gcc $(CFLAGS) BasicAlloc BasicAlloc.c

Calloc:
	gcc $(CFLAGS) Calloc Calloc.c

DoubleFree:
	gcc $(CFLAGS) DoubleFree DoubleFree.c

FreeUnalloc:
	gcc $(CFLAGS) FreeUnalloc FreeUnalloc.c

LeakDetect:
	gcc $(CFLAGS) LeakDetect LeakDetect.c

Realloc:
	gcc $(CFLAGS) Realloc Realloc.c

RepeatedAlloc:
	gcc $(CFLAGS) RepeatedAlloc RepeatedAlloc.c

VarySizesAlloc:
	gcc $(CFLAGS) VarySizesAlloc VarySizesAlloc.c

clean:
	rm BasicAlloc Calloc DoubleFree FreeUnalloc LeakDetect Realloc RepeatedAlloc VarySizesAlloc