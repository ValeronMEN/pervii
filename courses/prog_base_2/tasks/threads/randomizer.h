#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED

typedef struct shared_s {
    int integer;
    HANDLE mu;
} shared_t;

void rand_function(LPVOID args);
HANDLE rand_handle(shared_t * data);

#endif // RANDOMIZER_H_INCLUDED
