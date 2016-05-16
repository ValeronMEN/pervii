#include <stdlib.h>
#include <string.h>

#include "patient.h"

#define MAX_NAME_SIZE 30

struct patient_s
{
    int index;
    char* name;
    char* surname;
    int days;
    char * diagnosis;
};

patient_t * patient_new(int index, char* name, char* surname, char* diagnosis, int days)
{
    patient_t * patient = malloc(sizeof(struct patient_s));
    patient->index = index;
    patient->name = malloc(MAX_NAME_SIZE * sizeof(char));
    strcpy(patient->name, name);
    patient->surname = malloc(MAX_NAME_SIZE * sizeof(char));
    strcpy(patient->surname, surname);
    patient->diagnosis = malloc(MAX_NAME_SIZE * sizeof(char));
    strcpy(patient->diagnosis, diagnosis);
    patient->days = days;
    return patient;
}

void patient_free(patient_t* patient)
{
    free(patient->name);
    free(patient->surname);
    free(patient);
}

int patient_getIndex(patient_t* patient)
{
    return patient->index;
}

char* patient_getDiagnosis(patient_t* patient)
{
    return patient->diagnosis;
}

char* patient_getName(patient_t* patient)
{
    return patient->name;
}

char* patient_getSurname(patient_t* patient)
{
    return patient->surname;
}

int patient_getDays(patient_t* patient)
{
    return patient->days;
}
