#include <stdio.h>
#include <stdlib.h>

#include "patient.h"

void patient_print(const patient_t * mypatient)
{
    printf("Name: %s\n"
           "Surname: %s\n"
           "Diagnosis: %i\n"
           "Days: %.1f\n"
           "Importance: %i\n"
           "Birthdate: %s\n",
           mypatient->name,
           mypatient->surname,
           mypatient->diagnosis,
           mypatient->days,
           mypatient->importance,
           mypatient->birthdate);
}

void patient_printList(const patient_t *dirSet, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("\n%i.\n", (i+1));
        patient_print(&dirSet[i]);
        printf("");
    }
}
