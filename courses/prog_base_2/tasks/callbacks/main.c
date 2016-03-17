#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

#define color_error SetConsoleTextAttribute(hConsole, 12)

typedef int (*IteratorCallback)(int);

int overCB(int any){
    printf("overCB: %i (>K)\n", any);
    return any;
}

int underCB(int any){
    printf("underCB: %i (<K)\n", any);
    return any;
}

int run(IteratorCallback cb, int * size, int any){
    (*size)++;
    return cb(any);
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int N, K;
    int * overSize;
    int * underSize;
    int a=0, b=0;

    overSize = &a;
    underSize = &b;

    srand(time(NULL));
    printf("Enter positive N of integer (range of infinite array)\n");
    if (scanf("%i", &N)<1){
        color_error;
        printf("Error. Bad value");
        return 1;
    }
    if (N<0){
        color_error;
        printf("Error. N < 0");
        return 1;
    }
    fflush(stdin);
    printf("Enter positive K of integer (boundary value for functions; N must be > than K)\n");
    if (scanf("%i", &K)<1){
        color_error;
        printf("Error. Bad value");
        return 1;
    }
    if (K<0){
        color_error;
        printf("Error. K < 0");
        return 1;
    }
    if (K>N){
        color_error;
        printf("Error. K > N");
        return 1;
    }
    fflush(stdin);

    printf("Press any key to exit\n");

    int any, lastOver=0, lastUnder=0;
    while(kbhit()==0){
        any = (rand() % (2*N)) - N;
        if (any>K){
            lastOver = run(overCB, overSize, any);
        }
        if (any<(-K)){
            lastUnder = run(underCB, underSize, any);
        }
        Sleep(100);
    }

    SetConsoleTextAttribute(hConsole, 13);
    printf("\nOver: %i\nUnder: %i\nLast value from overCB: %i\nLast value from underCB: %i\n", *overSize, *underSize, lastOver, lastUnder);
    system("pause");
    return 0;
}


