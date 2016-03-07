#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include <string.h>

struct list_xy{
    int xcoord;
    int ycoord;
    char * name;
};

typedef struct list_s list_t;

typedef enum list_status{
    LIST_OK,
    LIST_OVERFLOW,
    LIST_UNDERFLOW,
    LIST_BADINDEXES,
    LIST_BADNAME,
} list_status;

list_t * list_new();
void list_free(list_t * mylist);

void list_add(list_t * mylist, int xcoord, int ycoord, char* name, int index);
void list_sub(list_t * mylist, int index);
int list_distance(list_t * mylist, int index1, int index2);

list_status list_getstatus(list_t * mylist);
int list_getcount(list_t * mylist);

void list_view(list_t * mylist);

#endif // LIST_H_INCLUDED
