#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct queue_s{
    int size;
    int head;
    int tail;
    struct_c deck[AMOUNT_OF_CARDS];
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
    if (myqueue->size == AMOUNT_OF_CARDS){
        myqueue->status = QUEUE_OVERFLOW;
        return;
    }
    if (myqueue->tail == AMOUNT_OF_CARDS){
        myqueue->tail = 0;
    }
    myqueue->size++;
    if (myqueue->size == AMOUNT_OF_CARDS){
        myqueue->status = QUEUE_MAX;
    }
    myqueue->deck[myqueue->tail] = card;
    myqueue->tail++;
}

struct_c queue_dequeue(queue_t * myqueue){
    myqueue->status = QUEUE_OK;
    if (myqueue->size == AMOUNT_OF_CARDS){
        myqueue->head = 0;
    }
    if (myqueue->head == myqueue->tail && myqueue->size == 0){
        myqueue->status = QUEUE_NULL;
        return;
    }
    struct_c card = myqueue->deck[myqueue->head];
    myqueue->deck[myqueue->head].suit = 0;
    myqueue->deck[myqueue->head].value = 0;
    myqueue->head++;
    myqueue->size--;
    return card;
}

queue_status queue_getstatus(queue_t * myqueue){
    return myqueue->status;
}

int queue_getsize(queue_t * myqueue){
    return myqueue->size;
}

void queue_view(queue_t * myqueue){
    int i=0, j=myqueue->head;
    while(i<myqueue->size){
        if (j == AMOUNT_OF_CARDS){
            j = j - AMOUNT_OF_CARDS;
        }
        printf("%i-%i ", myqueue->deck[j].value, myqueue->deck[j].suit);
        j++; i++;
    }
    puts("");
}

