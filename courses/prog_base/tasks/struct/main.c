#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Monitors {
   float diagonal;
   char name[100];
   int series;
};

int count(int size, struct Monitors arr[size]){
    int i, amount=0;
    for (i=0; i<size; i++){
        if (arr[i].diagonal>=17){
            amount++;
        }
    }
    return amount;
}

void change(struct Monitors * pVar, const char * newValue){
    strcpy(pVar->name, newValue);
}

void print(struct Monitors * pVar){
   printf("Diagonal of monitor is: %0.2f\nDesigner of monitor is: %s\nSeries of monitor is: %i\n\n", pVar->diagonal, pVar->name, pVar->series);
}

int main(void){
     int i, q;
     char newname[100];

     struct Monitors arr[3]={{13.5, "asus", 13456},{17.5, "lenovo", 36753},{18.5, "acer", 67584}};
     int size=3;

     for(i=0;i<size;i++){
        print(&arr[i]);
     }

     printf("An amount of monitors with diagonal >= 17 is: %i\n\n", count(3, arr));

     printf("Enter the index of monitor: ");
     scanf("%i", &q);
     if (q>=size||q<0){
        printf("Failed index of monitor");
        return 1;
     }
     printf("Enter the new name of designer of monitor: ");
     scanf("%s", newname);

     puts("");
     change(&(arr[q]), newname);

     print(&arr[q]);

     return 0;
}
