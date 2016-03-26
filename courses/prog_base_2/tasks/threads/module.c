#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "randomizer.h"
#include "negativewriter.h"

void rand_function(LPVOID args){
    shared_t * data = (shared_t *)args;
    //всё-таки WaitForSingleObject должен быть обязательно внутри, иногда вылазят левые числа (если он снаружи)
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
