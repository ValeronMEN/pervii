#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char * tmp;
    int * minimal;
    int * i;

    tmp = malloc(100*sizeof(char));
    minimal = malloc(sizeof(int));
    i = malloc(sizeof(int));

    gets(tmp);
    *minimal = *tmp;

    for((*i)=0; (*i)<strlen(tmp); (*i)++){
        if (*(tmp+*i)<(*minimal)){
            *minimal = *(tmp+*i);
        }
    }

    printf("Character with minimum ASCII code has code: %i,\nCharacter is %c\n", *minimal, *minimal);

    free(tmp);
    free(minimal);
    free(i);

    return 0;
}
