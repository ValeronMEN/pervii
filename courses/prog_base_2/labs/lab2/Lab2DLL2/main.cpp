#include <stdio.h>
#include <stdlib.h>

#include "main.h"

static int lib2_getsum(queue_t * myqueue){
    int size = queue_getsize(myqueue);
    int i, sum = 0, temp;
    for(i=0; i<size; i++){
        temp = queue_dequeue(myqueue);
        sum += temp;
        queue_enqueue(myqueue, temp);
    }
    return sum;
}

int reaction(queue_t * myqueue){
    int sum = lib2_getsum(myqueue);
    printf("\nProcessing...");
    while(sum>=50){
        queue_dequeue(myqueue);
        sum = lib2_getsum(myqueue);
    }
    printf("\nSum of elements is %i (<50)\n\n", sum);
    return 0;
}

int compare(queue_t * myqueue){
    int sum = lib2_getsum(myqueue);
    if (sum>100){
        printf("\nSum of elements is %i (>100)", sum);
        return 1;
    }
    return 0;
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
