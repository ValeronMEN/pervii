#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list_s{
    int size;
    struct_c deck[MAX_LIST_SIZE];
    list_status status;
};

list_t * list_new(){
    list_t * mylist = malloc(sizeof(struct list_s));
    mylist->size = 0;
    mylist->status = LIST_OK;
    return mylist;
}

void list_free(list_t * mylist){
    free(mylist);
}

void list_add(list_t * mylist, struct_c data, int index){
    int i;
    mylist->status = LIST_OK;
    if (mylist->size==MAX_LIST_SIZE){
        mylist->status = LIST_OVERFLOW;
        return;
    }
    if (index>mylist->size||index<0){
        index=mylist->size;
    }
    else{
        for(i=mylist->size; i>index; i--){
            mylist->deck[i] = mylist->deck[i-1];
        }
    }
    mylist->size+=1;
    mylist->deck[index] = data;
    return;
}

struct_c list_sub(list_t * mylist, int index){
    int i;
    mylist->status = LIST_OK;
    struct_c card;
    card.value = 0;
    card.suit = 0;
    if (mylist->size==0){
        mylist->status = LIST_UNDERFLOW;
        return card;
    }
    if (index>=(mylist->size)&&index<0){
        return card;
    }
    card = mylist->deck[index];
        for(i=index; i<mylist->size; i++){
            mylist->deck[i] = mylist->deck[i-1];
        }
    mylist->size-=1;
    return card;
}

list_status list_getstatus(list_t * mylist){
    return mylist->status;
}

int list_getcount(list_t * mylist){
    return mylist->size;
}

void list_view(list_t * mylist){
    int i;
    for(i=0; i<mylist->size; i++){
        printf("%i-%i ", mylist->deck[i].value, mylist->deck[i].suit);
    }
}
