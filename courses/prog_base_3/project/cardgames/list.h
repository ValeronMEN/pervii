#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MAX_LIST_SIZE 36
#include "drunkard.h"

typedef struct list_s list_t;

typedef enum list_status{
    LIST_OK,
    LIST_OVERFLOW,
    LIST_UNDERFLOW,
} list_status;

list_t * list_new();
void list_free(list_t * mylist);

void list_add(list_t * mylist, struct_c data, int index);
struct_c list_sub(list_t * mylist, int index);

list_status list_getstatus(list_t * mylist);
int list_getcount(list_t * mylist);

void list_view(list_t * mylist);

#endif // LIST_H_INCLUDED
