#include <math.h>
#include "list.h"

#define MAX_LIST_SIZE 100
#define MAX_NAME_SIZE 10

struct list_s{
    int size;
    struct list_xy * arr;
    list_status status;
};

list_t * list_new(){
    list_t * mylist = malloc(sizeof(struct list_s));
    mylist->arr = malloc(MAX_LIST_SIZE * (sizeof(struct list_xy)));
    mylist->arr->name = malloc(MAX_LIST_SIZE * MAX_NAME_SIZE * sizeof(char));
    mylist->size = 0;
    mylist->status = LIST_OK;
    return mylist;
}

void list_free(list_t * mylist){
    free(mylist->arr->name);
    free(mylist->arr);
    free(mylist);
}

void list_add(list_t * mylist, int xcoord, int ycoord, char* name, int index){
    int i;
    mylist->status = LIST_OK;
    if (mylist->size==MAX_LIST_SIZE){
        mylist->status = LIST_OVERFLOW;
        return;
    }
    if (strlen(name)>MAX_NAME_SIZE){
        mylist->status = LIST_BADNAME;
        return;
    }
    if (index>mylist->size||index<0){
        index=mylist->size;
    }
    else{
        for(i=mylist->size; i>index; i--){
            *((&mylist->arr->xcoord)+i*3)=*((&mylist->arr->xcoord)+(i-1)*3);
            *((&mylist->arr->ycoord)+i*3)=*((&mylist->arr->ycoord)+(i-1)*3);
            strcpy(mylist->arr->name+i*MAX_NAME_SIZE, mylist->arr->name+(i-1)*MAX_NAME_SIZE);
        }
    }
    mylist->size+=1;
    *((&mylist->arr->xcoord)+index*3)=xcoord;
     *((&mylist->arr->ycoord)+index*3)=ycoord;
    strcpy(mylist->arr->name+index*MAX_NAME_SIZE, name);
}

void list_sub(list_t * mylist, int index){
    int i;
    mylist->status = LIST_OK;
    if (mylist->size==0){
        mylist->status = LIST_UNDERFLOW;
        return;
    }
    if (index<=(mylist->size)&&index>=0){
        for(i=index; i<mylist->size; i++){
            *((&mylist->arr->xcoord)+i*3)=*((&mylist->arr->xcoord)+(i+1)*3);
            *((&mylist->arr->ycoord)+i*3)=*((&mylist->arr->ycoord)+(i+1)*3);
            strcpy(mylist->arr->name+i*MAX_NAME_SIZE, mylist->arr->name+(i+1)*MAX_NAME_SIZE);
        }
    }
    mylist->size-=1;
}

int list_distance(list_t * mylist, int index1, int index2){
    mylist->status = LIST_OK;
    if (index1<0||index2<0||index1>=mylist->size||index2>=mylist->size){
        mylist->status = LIST_BADINDEXES;
        return -1;
    }
    return sqrt((pow((*((&mylist->arr->xcoord)+index1*3)-*((&mylist->arr->xcoord)+index2*3)), 2))+(pow((*((&mylist->arr->ycoord)+index1*3)-*((&mylist->arr->ycoord)+index2*3)), 2)));
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
        printf("%s: x: %i, y: %i\n", mylist->arr->name+i*MAX_NAME_SIZE, *((&mylist->arr->xcoord)+i*3), *((&mylist->arr->ycoord)+i*3));
    }
}
