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
    //myqueue->deck = malloc(36 * sizeof(struct card));
    myqueue->size = 0;
    myqueue->status = QUEUE_OK;
    myqueue->head = myqueue->tail = 0;
    return myqueue;
}

void queue_free(queue_t * myqueue){
    //free(myqueue->deck);
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
    if (myqueue->tail==myqueue->head&&myqueue->size+1==36){
        myqueue->status = QUEUE_MAX;
    }
    myqueue->deck[myqueue->tail] = card;
    myqueue->tail++;
    myqueue->size++;
}

struct_c queue_dequeue(queue_t * myqueue, int index){
    myqueue->status = QUEUE_OK;
    if (myqueue->head == 0){
        myqueue->head=35;
    }
    if (myqueue->head==myqueue->tail&&myqueue->size==0){
        myqueue->status = QUEUE_NULL;
        return;
    }
    struct_c card = myqueue->deck[myqueue->head];
    //deck[myqueue->head]->value = EMPTY;
    //deck[myqueue->head]->suit = NOSUIT;
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
    int i;
    for (i=0; i<myqueue->size; i++){
        printf("%i-%i ", myqueue->deck[i].value, myqueue->deck[i].suit);
    }
    puts("");
}

