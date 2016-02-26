#include <math.h>
#include "list.h"

#define MAX_LIST_SIZE 100
#define MAX_NAME_SIZE 50

struct list_s{
    int * arr_x;
    int * arr_y;
    char ** name;
    int size;
    list_status status;
};

list_t * newlist(){
    list_t * mylist = malloc(sizeof(struct list_s));
    mylist->name = malloc(MAX_LIST_SIZE * MAX_NAME_SIZE * sizeof(char));
    mylist->arr_x = malloc(MAX_LIST_SIZE * sizeof(int));
    mylist->arr_y = malloc(MAX_LIST_SIZE * sizeof(int));
    mylist->size = 0;
    mylist->status = LIST_OK;
    return mylist;
}

void list_free(list_t * mylist){
    free(mylist->arr_x);
    free(mylist->arr_y);
    free(mylist->name);
    free(mylist);
}

void list_add(list_t * mylist, int xcoord, int ycoord, char* name, int index){
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
            *(mylist->arr_x+i)=*(mylist->arr_x+i-1);
            *(mylist->arr_y+i)=*(mylist->arr_y+i-1);
            strcpy(mylist->name+i, mylist->name+i-1);
        }
    }
    mylist->size+=1;
    mylist->arr_x[index]=xcoord;
    mylist->arr_y[index]=ycoord;
    mylist->name[index] = name;
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
            *(mylist->arr_x+i)=*(mylist->arr_x+i+1);
            *(mylist->arr_y+i)=*(mylist->arr_y+i+1);
            strcpy(mylist->name+i, mylist->name+i+1);
        }
    }
    mylist->size-=1;
}

int distance(list_t * mylist, int index1, int index2){
    mylist->status = LIST_OK;
    if (index1<0||index2<0||index1>mylist->size||index2>mylist->size){
        mylist->status = LIST_BADINDEXES;
        return;
    }
    return sqrt((pow((mylist->arr_x[index1]-mylist->arr_x[index2]), 2))+(pow((mylist->arr_y[index1]-mylist->arr_y[index2]), 2)));
}

list_status list_getstatus(list_t * mylist){
    return mylist->status;
}

int list_getcount(list_t * mylist){
    return mylist->size;
}

void view(list_t * mylist){
    int i;
    for(i=0; i<mylist->size; i++){
        printf("%s: x: %i, y: %i\n", *(mylist->name+i), *(mylist->arr_x+i), *(mylist->arr_y+i));
    }
}
