#include "heap.h"
#include "memory.h"

#define MAX_HEAP_SIZE 100

struct heap_s{
    int size;
    int id;
    heap_status status;
};

struct memory_s{
    char * data;
    int size;
    int id;
    memory_status status;
};

heap_t * heap_new(int id){
    heap_t * myheap = malloc(sizeof(struct heap_s));
    myheap->size = MAX_HEAP_SIZE;
    myheap->status = HEAP_OK;
    myheap->id = id;
    return myheap;
}

heap_t * heap_new_manually(int id, int size){
    heap_t * myheap = malloc(sizeof(struct heap_s));
    myheap->size = size;
    myheap->status = HEAP_OK;
    myheap->id = id;
    return myheap;
}

void heap_free(heap_t * myheap){
    free(myheap);
}

memory_t * heap_newMemory(heap_t * myheap, int size){
    myheap->status = HEAP_OK;
    struct memory_s * mymemory = malloc(sizeof(struct memory_s));
    mymemory->data = malloc(sizeof(char) * myheap->size);
    mymemory->data = "";
    mymemory->status = MEMORY_EMPTY;
    mymemory->id = myheap->id;
    if (size>myheap->size){
        mymemory->size = 0;
        myheap->status = HEAP_OVERFLOW;
        return mymemory;
    }
    mymemory->size = size;
    myheap->size = myheap->size - size;
    return mymemory;
}

void heap_freeMemory(memory_t * mymemory, heap_t * myheap){
    if (myheap->id != mymemory->id){
        mymemory->status = MEMORY_BADHEAP;
        return;
    }
    int size = mymemory->size;
    free(mymemory->data);
    free(mymemory);
    myheap->size = myheap->size + size;
}

int heap_getSize(heap_t * myheap){
    return myheap->size;
}

heap_status heap_getstatus(heap_t * myheap){
    return myheap->status;
}
