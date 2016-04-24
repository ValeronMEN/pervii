#include "patient.h"

typedef struct db_s db_t;

db_t * db_new(char *);
void db_delete(db_t *);

void db_patient_insert(db_t * , patient_t * );
patient_t * db_patient_get(db_t * , int );
void db_patient_update(db_t *, patient_t * , int);
void db_patient_delete(db_t *, int);

int db_count(db_t *);
int db_filter(db_t *, double, int, patient_t *, int);
