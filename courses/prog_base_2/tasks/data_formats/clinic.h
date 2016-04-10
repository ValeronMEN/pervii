#include <time.h>

#define MAX_SIZE_OF_STRING 50

typedef struct diagnosis_s{
    char name[MAX_SIZE_OF_STRING];
    int risk;
} diagnosis_t;

typedef struct patient_s{
    char name[MAX_SIZE_OF_STRING];
    char surname[MAX_SIZE_OF_STRING];
    char treatment[MAX_SIZE_OF_STRING];
    struct tm birthday;
    float importance;
    int roomnumber;
    struct diagnosis_s diagnosis;
} patient_t;

patient_t * patient_new();
void patient_delete(patient_t * patient);
diagnosis_t * diagnosis_new();
void diagnosis_delete(diagnosis_t * diagnosis);

void xmlParse(patient_t * patientSet[], const char * XMLFileName);
void print_function(patient_t * patient);
