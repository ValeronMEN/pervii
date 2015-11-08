#include <string.h>

char * process(char * resultStr, const char * textLines[], int linesNum, const char * extraStr){
 int i, n=0, nomersbolshim=0, j, max=0;
 char piece[100];
 char * ppiece;
 ppiece = piece;

 ppiece = strstr(textLines[0], extraStr);
 if (ppiece==NULL){
        n=0;
        }
 else {
    n=1;
    for (i=0; i<100; i++){
            ppiece = strstr(ppiece+1, extraStr);
            if (ppiece==NULL){
               break;
                }
                n++;
        }
 }

max  = n;

for (j=0; j<linesNum; j++){
ppiece = strstr(textLines[j], extraStr);
 if (ppiece==NULL){
        n=0;
        }
 else {
    n=1;
    for (i=0; i<100; i++){
            ppiece = strstr(ppiece+1, extraStr);
            if (ppiece==NULL){
               break;
                }
                n++;
        }

 }
 if (max<n){
            max=n;
            nomersbolshim = j;}
}

 sprintf(resultStr, "%i %s", max, textLines[nomersbolshim]);
 return resultStr;
}
