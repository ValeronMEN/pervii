#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#define MAX_PATIENT_STR_SIZE 20
#define MAX_DATE_STR_SIZE 11
#define SMALL_BUFFER_SIZE 1024
#define BIG_BUFFER_SIZE 10240
#define STRING_MAX_SIZE 100

typedef struct patient_s{
    int id;
    char name[STRING_MAX_SIZE];
    char surname[STRING_MAX_SIZE];
    char diagnosis[STRING_MAX_SIZE];
    double days;
    int importance;
    char birthdate[STRING_MAX_SIZE];
} patient_t;

typedef struct patient_s patient_t;

patient_t * patient_new(void); // create a patient
void patient_free(patient_t * self); // free patient

void patient_init(patient_t * self, char * name, char * surname, char * diagnosis, char * birthday, int, double, int);
void patient_swap(patient_t * self, patient_t * selfSwap); // swap two patients

char * patient_json(patient_t * self);
char * patient_html(patient_t * self, int ID);
char * patient_getName(patient_t * self);
char * patient_getSurname(patient_t * self);
void patient_print(const patient_t * mypatient);
void patient_printList(const patient_t *dirSet, int len);

#endif // PATIENT_H_INCLUDED
