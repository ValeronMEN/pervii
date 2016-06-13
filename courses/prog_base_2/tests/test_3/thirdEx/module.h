#include "student.h"

typedef struct db_s db_t;

db_t * db_new(char *);
void db_delete(db_t *);

void db_student_insert(db_t * , student_t * );
student_t * db_student_get(db_t * , int);

void db_student_delete(db_t *, char*);

int db_count(db_t *);
int db_filter(db_t *, char* , student_t *, int);
