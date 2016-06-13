#include <stdio.h>
#include <stdlib.h>

#include "student.h"

void student_print(const student_t * myStudent)
{
    printf("Name: %s\n"
           "Surname: %s\n"
           "Fathername: %s\n"
           "City: %s\n"
           "Number: %i\n"
           "Birthdate: %s\n",
           myStudent->name,
           myStudent->surname,
           myStudent->father,
           myStudent->city,
           myStudent->number,
           myStudent->birthdate);
}

void student_printList(const student_t *dirSet, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("\n%i.\n", (i+1));
        student_print(&dirSet[i]);
        printf("");
    }
}
