//N-2

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(){
int arr[100];
char str[100];
int max, i, number=1;
int size=0;
char *p;
char del[] = " ";

FILE *fp;

fp = fopen("input.txt", "r");
if (fp == NULL){
    printf("File not found\n");
    return EXIT_FAILURE;
}

fgets(str, 100, fp);
rewind(fp);
printf("Input string is: %s\n", str);

p = strtok(str, del);
while(p != NULL){
size++;
p = strtok(NULL, del);
}

i=0;

for(i=0; i<size; i++){
    fscanf(fp, "%i", (arr+i));
    printf("%i number is %i\n", number, *(arr+i));
    if(i==0){
        max = arr[0];
    }
    if (arr[i]>max){
        max = arr[i];
    }
    number++;
}

fclose(fp);

printf("\nMaximum is %i", max);
return 0;
}

