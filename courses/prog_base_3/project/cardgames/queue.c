#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define MAX_NAME_SIZE 10

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
    myqueue->status = QUEUE_OK;
    return myqueue;
}

void queue_free(queue_t * myqueue){
    free(myqueue);
}

void queue_add(queue_t * myqueue, struct_c card){

}

struct_c queue_sub(queue_t * myqueue, int index){

}

queue_status queue_getstatus(queue_t * myqueue){
    return myqueue->status;
}

int queue_getcount(queue_t * myqueue){
    return myqueue->size;
}
/*
void queue_view(queue_t * myqueue){

}
*/
