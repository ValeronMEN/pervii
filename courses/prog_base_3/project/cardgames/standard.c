#include <stdio.h>
#include <stdlib.h>

#include "standard.h"

void coloda_fill_36(struct_c * deck){
    int i;
    for (i=0; i<36; i++){
        struct_c * pointer = deck + i;
        pointer->value = EMPTY;
        pointer->suit = NOSUIT;
    }
    return;
}
