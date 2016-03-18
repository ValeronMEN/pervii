#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "memory.h"

typedef struct heap_s heap_t;
typedef struct memory_s memory_t;

typedef enum heap_status{
    HEAP_OK,
    HEAP_OVERFLOW
} heap_status;

heap_t * heap_new(int id);
heap_t * heap_new_manually(int id, int size);
void heap_free(heap_t * myheap);

memory_t * heap_newMemory(heap_t * myheap, int size);
void heap_freeMemory(memory_t * mymemory, struct heap_s * myheap);

heap_status heap_getstatus(heap_t * myheap);
int heap_getSize(heap_t * myheap);

#endif // HEAP_H_INCLUDED
