#include <stdlib.h>

void fillRand(int mat[4][4]){
    int i, j;
srand(time(NULL));
for (i = 0; i < 4; i++)
{
    for (j = 0; j < 4; j++)
    {
        mat[i][j] = rand() % 1999 - 999;
    }
}
}

void rotateCW180(int mat[4][4]){
int a11, a12, a13, a14;
int a21, a22, a23, a24;
int a31, a32, a33, a34;
int a41, a42, a43, a44;

a11 = mat[0][0]; a12 = mat[0][1]; a13 = mat[0][2]; a14 = mat[0][3];
a21 = mat[1][0]; a22 = mat[1][1]; a23 = mat[1][2]; a24 = mat[1][3];
a31 = mat[2][0]; a32 = mat[2][1]; a33 = mat[2][2]; a34 = mat[2][3];
a41 = mat[3][0]; a42 = mat[3][1]; a43 = mat[3][2]; a44 = mat[3][3];

mat[0][0] = a44 ; mat[0][1] =  a43 ; mat[0][2] = a42  ; mat[0][3] =  a41 ;
mat[1][0] = a34 ; mat[1][1] =  a33 ; mat[1][2] = a32  ; mat[1][3] =  a31 ;
mat[2][0] = a24 ; mat[2][1] =  a23 ; mat[2][2] = a22  ; mat[2][3] =  a21 ;
mat[3][0] = a14 ; mat[3][1] =  a13 ; mat[3][2] = a12  ; mat[3][3] =  a11 ;
}

void flipH(int mat[4][4]){
int a11, a12, a13, a14;
int a21, a22, a23, a24;
int a31, a32, a33, a34;
int a41, a42, a43, a44;

a11 = mat[0][0]; a12 = mat[0][1]; a13 = mat[0][2]; a14 = mat[0][3];
a21 = mat[1][0]; a22 = mat[1][1]; a23 = mat[1][2]; a24 = mat[1][3];
a31 = mat[2][0]; a32 = mat[2][1]; a33 = mat[2][2]; a34 = mat[2][3];
a41 = mat[3][0]; a42 = mat[3][1]; a43 = mat[3][2]; a44 = mat[3][3];

mat[0][0] = a14; mat[0][1] = a13; mat[0][2] = a12; mat[0][3] = a11;
mat[1][0] = a24; mat[1][1] = a23; mat[1][2] = a22; mat[1][3] = a21;
mat[2][0] = a34; mat[2][1] = a33; mat[2][2] = a32; mat[2][3] = a31;
mat[3][0] = a44; mat[3][1] = a43; mat[3][2] = a42; mat[3][3] = a41;
}

void transposSide(int mat[4][4]){
int a11, a12, a13, a14;
int a21, a22, a23, a24;
int a31, a32, a33, a34;
int a41, a42, a43, a44;

a11 = mat[0][0]; a12 = mat[0][1]; a13 = mat[0][2]; a14 = mat[0][3];
a21 = mat[1][0]; a22 = mat[1][1]; a23 = mat[1][2]; a24 = mat[1][3];
a31 = mat[2][0]; a32 = mat[2][1]; a33 = mat[2][2]; a34 = mat[2][3];
a41 = mat[3][0]; a42 = mat[3][1]; a43 = mat[3][2]; a44 = mat[3][3];

mat[0][0] = a44; mat[0][1] = a34; mat[0][2] = a24; mat[0][3] = a14;
mat[1][0] = a43; mat[1][1] = a33; mat[1][2] = a23; mat[1][3] = a13;
mat[2][0] = a42; mat[2][1] = a32; mat[2][2] = a22; mat[2][3] = a12;
mat[3][0] = a41; mat[3][1] = a31; mat[3][2] = a21; mat[3][3] = a11;
}
