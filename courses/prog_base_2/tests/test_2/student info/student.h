#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "cJSON/cJSON.h"

#define MAX_PATIENT_STR_SIZE 20
#define MAX_DATE_STR_SIZE 11
#define SMALL_BUFFER_SIZE 1024
#define BIG_BUFFER_SIZE 10240

typedef struct student_s student_t;

student_t * student_new(void); // create a student
void student_free(student_t * self); // free student

void student_init(student_t * self, char * name, char * group, int variant);
void student_swap(student_t * self, student_t * selfSwap); // swap two patients

char * student_json(student_t * self, int check);
char * student_html(student_t * self, int ID);
char * student_getName(student_t * self);
char * student_getGroup(student_t * self);

#endif // STUDENT_H_INCLUDED
