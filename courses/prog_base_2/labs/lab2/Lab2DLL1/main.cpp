#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int compare(queue_t * myqueue){
    //check length of queue > 10
    if (queue_getsize(myqueue) > 10){
        printf("\nSize of queue > 10");
        return 1;
    }
    return 0;
}

int reaction(queue_t * myqueue){
    int i, sum = 0;
    printf("\nProcessing...");
    for (i=0; i<5; i++){
        sum += queue_dequeue(myqueue);
    }
    printf("\nSum of the first 5 elements: %i\n\n", sum);
    return sum;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
