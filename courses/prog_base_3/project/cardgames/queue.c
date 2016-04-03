#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct queue_s{
    int size;
    int head;
    int tail;
    struct_c deck[36];
    queue_status status;
};

queue_t * queue_new(){
    queue_t * myqueue = malloc(sizeof(struct queue_s));
    myqueue->size = 0;
    myqueue->status = QUEUE_NULL;
    myqueue->head = myqueue->tail = 0;
    return myqueue;
}

void queue_free(queue_t * myqueue){
    free(myqueue);
}

void queue_enqueue(queue_t * myqueue, struct_c card){
    myqueue->status = QUEUE_OK;
    if (myqueue->size==36){
        myqueue->status = QUEUE_OVERFLOW;
        return;
    }
    if (myqueue->tail == 36){
        myqueue->tail=0;
    }
    myqueue->size++;
    if (myqueue->size==36){
        myqueue->status = QUEUE_MAX;
    }
    myqueue->deck[myqueue->tail] = card;
    myqueue->tail++;
}

struct_c queue_dequeue(queue_t * myqueue){
    myqueue->status = QUEUE_OK;
    if (myqueue->head == 0){
        myqueue->head==35;
    }
    if (myqueue->head==myqueue->tail&&myqueue->size==0){
        myqueue->status = QUEUE_NULL;
        return;
    }
    struct_c card = myqueue->deck[myqueue->head];
    myqueue->head++;
    myqueue->size--;
    return card;
}

queue_status queue_getstatus(queue_t * myqueue){
    return myqueue->status;
}

int queue_getcount(queue_t * myqueue){
    return myqueue->size;
}

void queue_view(queue_t * myqueue){
    int i=0, j=myqueue->head;
    while(i<myqueue->size){
        if (j==36){
            j=j-36;
        }
        printf("%i-%i ", myqueue->deck[j].value, myqueue->deck[j].suit);
        j++; i++;
    }
    puts("");
}

