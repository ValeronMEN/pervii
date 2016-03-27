#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED

typedef struct shared_s shared_t;

shared_t * module_new();

void rand_function(LPVOID args);
HANDLE rand_handle(shared_t * data);

void module_free(shared_t *);

#endif // RANDOMIZER_H_INCLUDED
