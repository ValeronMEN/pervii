//n2. babenko
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct Pryamokyt {
    int xcoord;
    int ycoord;
    int dovzhina;
    int vusota;
};

void random (int size, struct  Pryamokyt p[size]) {
    int i;
    for(i = 0; i < size; i++) {
        p[i].xcoord = rand() % 10;
        p[i].ycoord = rand() % 10;
        p[i].dovzhina = rand() % 20;
        p[i].vusota = rand() % 20;
    }
}

int peretin(int ind1, int ind2, struct Pryamokyt p1[ind1], struct Pryamokyt p2[ind2]){
    if (((p1[ind1].xcoord+p1[ind1].dovzhina)>p1[ind2].xcoord)&&((p2[ind1].ycoord+p2[ind1].vusota)>p2[ind2].ycoord)){
        return 0;
    }
    else {
        return 1;
    }
}

int main(void){

    int i, j;
    struct Pryamokyt p[10];

    srand(time(NULL));
    random(10, p);

    int res = peretin (1, 2, &p[1], &p[2]);
    if (res == 0){
        printf("peretin isnuie");
    }
    else {
        printf("peretin ne isnuie");
    }
    puts("\n");

    for (i=0; i<10; i++){
            for (j=0; j<10; j++){
        printf("%i, %i. ", i, j);

        int res = peretin (i, j, &p[i], &p[j]);
        if (res == 0){
        printf("peretin isnuie");
        }
        else {
        printf("peretin ne isnuie");
        }
        puts("");
    }
    }
    return 0;
}

