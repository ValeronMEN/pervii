#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX_SIZE_OF_QUEUE 50

typedef struct queue_s queue_t;

typedef enum queue_status{
    QUEUE_OK,
    QUEUE_OVERFLOW,
    QUEUE_UNDERFLOW,
} queue_status;

queue_t * queue_new();
void queue_free(queue_t * myqueue);

void queue_enqueue(queue_t * myqueue, int value);
int queue_dequeue(queue_t * myqueue);

int queue_getsize(queue_t * myqueue);

void queue_view(queue_t * myqueue);

#endif // QUEUE_H_INCLUDED
