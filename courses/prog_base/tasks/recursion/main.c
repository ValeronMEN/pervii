#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int function1(char * stroka, int * pointer, int size){
    if (*pointer == 5) return 1;

    if (size==0) return 0;

    printf("String is: ");
    puts(stroka);

    if(isdigit(*stroka)){
        (*pointer)++;
        printf("Am amount of numbers: %i\n", *pointer);
    }

    function1(stroka+1, pointer, size-1);

    if (*pointer == 5) return 1;

    return 0;
}

int main(void){
    char stroka[100];
    int * pointer;
    int k=0;

    pointer = &k;

    gets(stroka);
    printf("An amount of elements in string: %i\n", strlen(stroka));
    return function1(stroka, pointer, strlen(stroka));
}
