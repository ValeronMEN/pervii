#include <stdlib.h>

void fillRand(int mat[4][4]){
    int i, j;
for (i = 0; i < 4; i++)
{
    for (j = 0; j < 4; j++)
    {
        mat[i][j] = rand() % 1999 - 999;
    }
}
}

void rotateCW180(int mat[4][4]){
int a[4][4];
int i, j;
for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            a[i][j]=mat[3-i][3-j];
        }
}
for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            mat[i][j]=a[i][j];
        }
}
}

void flipH(int mat[4][4]){
int a[4][4];
int i, j;
for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            a[i][j]=mat[i][3-j];
        }
}
for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            mat[i][j]=a[i][j];
        }
}
}

void transposSide(int mat[4][4]){
int a[4][4];
int i, j;
for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            a[i][j]=mat[j][i];
        }
}
for (i=0; i<4; i++){
        for (j=0; j<4; j++){
            mat[i][j]=a[3-i][3-j];
        }
}
}
