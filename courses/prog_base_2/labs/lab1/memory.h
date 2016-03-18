#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

typedef enum memory_status{
    MEMORY_OK,
    MEMORY_OVERFLOW,
    MEMORY_BADDATA,
    MEMORY_EMPTY,
    MEMORY_BADHEAP
} memory_status;

typedef struct memory_s memory_t;

void memory_enter(memory_t * mymemory, char * data);
char * memory_read(memory_t * mymemory);

memory_status memory_getstatus(memory_t * mymemory);
int memory_getSize(memory_t * mymemory);

#endif // MEMORY_H_INCLUDED
