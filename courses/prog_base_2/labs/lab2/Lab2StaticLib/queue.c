#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct queue_s{
    int size;
    int head;
    int tail;
    int data[MAX_SIZE_OF_QUEUE];
    queue_status status;
};

queue_t * queue_new(){
    queue_t * myqueue = malloc(sizeof(struct queue_s));
    myqueue->size = 0;
    myqueue->status = QUEUE_OK;
    myqueue->head = myqueue->tail = 0;
    return myqueue;
}

void queue_free(queue_t * myqueue){
    free(myqueue);
}

void queue_enqueue(queue_t * myqueue, int value){
    myqueue->status = QUEUE_OK;
    if (myqueue->size == MAX_SIZE_OF_QUEUE){
        myqueue->status = QUEUE_OVERFLOW;
        return;
    }
    if (myqueue->tail == MAX_SIZE_OF_QUEUE){
        myqueue->tail = 0;
    }
    myqueue->size++;
    myqueue->data[myqueue->tail] = value;
    myqueue->tail++;
}

int queue_dequeue(queue_t * myqueue){
    myqueue->status = QUEUE_OK;
    if (myqueue->head == MAX_SIZE_OF_QUEUE){
        myqueue->head = 0;
    }
    if (myqueue->size == 0){
        myqueue->status = QUEUE_UNDERFLOW;
        return 0;
    }
    int value = myqueue->data[myqueue->head];
    myqueue->head++;
    myqueue->size--;
    return value;
}

queue_status queue_getstatus(queue_t * myqueue){
    return myqueue->status;
}

int queue_getsize(queue_t * myqueue){
    return myqueue->size;
}

void queue_view(queue_t * myqueue){
    int i=0, j=myqueue->head;
    printf("Queue is: ");
    while(i<myqueue->size){
        if (j == MAX_SIZE_OF_QUEUE){
            j = j - MAX_SIZE_OF_QUEUE;
        }
        printf("%i ", myqueue->data[j]);
        j++; i++;
    }
    puts("");
}
