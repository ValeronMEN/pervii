#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "randomizer.h"
#include "negativewriter.h"

struct shared_s {
    int integer;
    HANDLE mu;
};

shared_t * module_new(){
    shared_t * mymodule = malloc(sizeof(struct shared_s));
    mymodule->mu = CreateMutex(
        NULL,
        FALSE,
        NULL);
    return mymodule;
}

void module_free(shared_t * mymodule){
    CloseHandle(mymodule->mu);
    free(mymodule);
}

void rand_function(LPVOID args){
    shared_t * data = (shared_t *)args;
    //WaitForSingleObject should always be inside. Sometimes there are positive numbers, if it's outside (4 threads)
    while(1){
        WaitForSingleObject(data->mu, INFINITE);
        data->integer = rand() % 511 - 255;
        ReleaseMutex(data->mu);
    }
}

void neg_function(LPVOID args){
    shared_t * data = (shared_t *)args;
    while(1){
        WaitForSingleObject(data->mu, INFINITE);
        if(data->integer<0){
            printf("%i\n", data->integer);
        }
        ReleaseMutex(data->mu);
    }
}

HANDLE rand_handle(shared_t * data){
    DWORD tId;
    HANDLE randomThread = CreateThread(
        NULL,
        0,
        (LPTHREAD_START_ROUTINE) rand_function,
        data,
        0,
        &tId);
    return randomThread;
}

HANDLE neg_handle(shared_t * data){
    DWORD tId;
    HANDLE negativeThread = CreateThread(
        NULL,
        0,
        (LPTHREAD_START_ROUTINE) neg_function,
        data,
        0,
        &tId);
    return negativeThread;
}
