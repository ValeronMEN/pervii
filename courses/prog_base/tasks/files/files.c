#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void fprocess(const char * pread, const char * pwrite){
char * str[200];
int i;
char *p;
char del[] = " ";

FILE *fp;

fp = fopen(pread, "r");
if (fp == NULL) {
    return EXIT_FAILURE;
}

fgets(str, 200, fp);

fclose(fp);

fp = fopen(pwrite, "w");
if (fp == NULL) {
    return EXIT_FAILURE;
}

p = strtok(str, del);
while(p != NULL){
    fprintf(fp, "%s\n", p);
    p = strtok(NULL, del);
}

fclose(fp);
return 0;
}
