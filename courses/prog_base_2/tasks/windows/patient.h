#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

typedef struct patient_s patient_t;

patient_t * patient_new(int index, char* name, char* surname, char* diagnosis, int days);
void patient_free(patient_t* );

int patient_getIndex(patient_t* );
char* patient_getName(patient_t* );
char* patient_getSurname(patient_t* );
int patient_getDays(patient_t* );
char * patient_getDiagnosis(patient_t* );

#endif // WORKER_H_INCLUDED
