#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "randomizer.h"
#include "negativewriter.h"

int main()
{
    srand(time(NULL));
    shared_t * data = module_new();

    HANDLE a = rand_handle(data);
    HANDLE b = neg_handle(data);
    HANDLE c = rand_handle(data);
    HANDLE d = neg_handle(data);

    Sleep(1000);

    TerminateThread(a, 0);
    TerminateThread(b, 0);
    TerminateThread(c, 0);
    TerminateThread(d, 0);

    CloseHandle(a);
    CloseHandle(b);
    CloseHandle(c);
    CloseHandle(d);

    module_free(data);
    return 0;
}
