#ifndef NEGATIVEWRITER_H_INCLUDED
#define NEGATIVEWRITER_H_INCLUDED

typedef struct shared_s shared_t;

shared_t * module_new();

void neg_function(LPVOID args);
HANDLE neg_handle(shared_t * data);

void module_free(shared_t *);

#endif // NEGATIVEWRITER_H_INCLUDED
