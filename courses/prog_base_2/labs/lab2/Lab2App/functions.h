#include "C:\Users\DrLove\Desktop\lab2\Lab2StaticLib\queue.h"

typedef int (*cmp_f)(queue_t * myqueue);
typedef void (*react_f)(queue_t * myqueue);

typedef struct dynamic_s {
    HANDLE hLib;
    cmp_f cmp;
    react_f react;
} dynamic_t;

dynamic_t * dynamic_init(const char * dllName);
void dynamic_clean(dynamic_t * dyn);

const char * userChoice();
