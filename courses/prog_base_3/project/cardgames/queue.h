#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "standard.h"

typedef struct queue_s queue_t;

typedef enum queue_status{
    QUEUE_OK,
    QUEUE_MAX,
    QUEUE_NULL,
} queue_status;

queue_t * queue_new();
void queue_free(queue_t * myqueue);

void queue_add(queue_t * myqueue, struct_c card);
struct_c queue_sub(queue_t * myqueue, int index);

int queue_getcount(queue_t * myqueue);

void queue_view(queue_t * myqueue);

#endif // QUEUE_H_INCLUDED
