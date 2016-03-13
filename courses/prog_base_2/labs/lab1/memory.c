#include "memory.h"

struct memory_s{
    char * data;
    int size;
    memory_status status;
};

void memory_enter(memory_t * mymemory, char * data){
    int i;
    mymemory->status = MEMORY_OK;
    if(strcmp(data, "")==0){
        mymemory->status = MEMORY_EMPTY;
        return;
    }
    for(i=0; i<strlen(data); i++){
        if(*(data+i)!='1'&&*(data+i)!='0'&&*(data+i)!=' '){
            mymemory->status = MEMORY_BADDATA;
            return;
        }
    }
    if (strlen(data)>mymemory->size){
        mymemory->status = MEMORY_OVERFLOW;
        return;
    }
    strcpy(&(mymemory->data), &data);
}

int memory_getSize(memory_t * mymemory){
    return mymemory->size;
}

char * memory_read(memory_t * mymemory){
    return mymemory->data;
}

memory_status memory_getstatus(memory_t * mymemory){
    return mymemory->status;
}
