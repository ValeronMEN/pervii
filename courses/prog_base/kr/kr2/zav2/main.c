//N-2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    struct Student * students[2];
    struct Laptop * laptops[2];
    printf("Enter structures data:\n\n");

    InitializeR(&(students[1]), &(students[2]));

    printf("Initialize default data...");

    InitializeD(&(students[1]), &(students[2]));
    return 0;
}
