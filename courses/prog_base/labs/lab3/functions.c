#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "advanced.h"

#define SCCP SetConsoleCursorPosition(hConsole, pos)
#define color_default SetConsoleTextAttribute(hConsole, 7)
#define standard system("cls"); showzone(size); printmatrix(size, mat); color_default

void myrandom(int size, float mat[size][size], int d1, int d2){
    int i, j;
    srand(time(NULL));
    if (d1==d2){
      for (i=0; i<size; i++){
       for (j=0; j<size; j++){
          *( *(mat+i) +j) = d1;
       }
    }
    return 0;
    }

    float k, g, h;
    if(d1>=0&&d2>=0){
    for (i=0; i<size; i++){
       for (j=0; j<size; j++){
            k = (float)(rand()%(d2-d1));
            h = (float)(rand()%10);
            g = (float)(h/10);
          *( *(mat+i) +j) = k+g+(float)d1;
       }
    }
    }

    if(d1<0&&d2<0){
    for (i=0; i<size; i++){
       for (j=0; j<size; j++){
            k = (float)((-1)*(rand()%(d2-d1)));
            h = (float)(rand()%10);
            g = (float)(h/10);
          *( *(mat+i) +j) = k-g+(float)d2;
       }
    }
    }

    if(d1<0&&d2>=0){
    for (i=0; i<size; i++){
       for (j=0; j<size; j++){
            k = (float)(rand()%(d1*(-1)+d2));
            h = (float)(rand()%10);
            g = (float)(h/10);
          *( *(mat+i) +j) = k+g+(float)d1;
       }
    }
    }
}

void help(int size){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    SetConsoleTextAttribute(hConsole, 7);
    pos.X=0; pos.Y=size*2+4; SCCP;

    printf("There are commands you can to do:");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    pos.X=2; pos.Y++; SCCP; printf("!null");
    pos.X=2; pos.Y++; SCCP; printf("!random");
    pos.X=2; pos.Y=pos.Y+2; SCCP; printf("!change");
    pos.X=2; pos.Y=pos.Y+2; SCCP; printf("!hor");
    pos.X=2; pos.Y++; SCCP; printf("!secdia");
    pos.X=2; pos.Y++; SCCP; printf("!rotate");
    pos.X=2; pos.Y++; SCCP; printf("!sumall");
    pos.X=2; pos.Y++; SCCP; printf("!sumcol");
    pos.X=2; pos.Y++; SCCP; printf("!sumund");
    pos.X=2; pos.Y++; SCCP; printf("!min1max1");
    pos.X=2; pos.Y=pos.Y+2; SCCP; printf("!minlmaxl");
    pos.X=2; pos.Y=pos.Y+2; SCCP; printf("!cmcm");
    pos.X=2; pos.Y=pos.Y+2; SCCP; printf("!exit");

    SetConsoleTextAttribute(hConsole, 7);
    pos.X=21; pos.Y=size*2+5; SCCP; printf("to zero all elements of the matrix");
    pos.X=21; pos.Y++; SCCP; printf("to fill with random numbers in the range that the user");
    pos.X=21; pos.Y++; SCCP; printf("entered in int type");
    pos.X=21; pos.Y++; SCCP; printf("to change the array element at index entered by the value");
    pos.X=21; pos.Y++; SCCP; printf("entered");
    pos.X=21; pos.Y++; SCCP; printf("to flip horizontally");
    pos.X=21; pos.Y++; SCCP; printf("to display relative to the secondary diagonal");
    pos.X=21; pos.Y++; SCCP; printf("to rotate the matrix clockwise by 180 degrees");
    pos.X=21; pos.Y++; SCCP; printf("to output the sum of elements of a matrix");
    pos.X=21; pos.Y++; SCCP; printf("to output the sum of a specified column");
    pos.X=21; pos.Y++; SCCP; printf("to output the sum of elements below the main diagonal");
    pos.X=21; pos.Y++; SCCP; printf("to change the first minimum and the first maximum element");
    pos.X=21; pos.Y++; SCCP; printf("in the matrix sometimes");
    pos.X=21; pos.Y++; SCCP; printf("to change the last minimum and last maximum elements in the");
    pos.X=21; pos.Y++; SCCP; printf("matrix sometimes");
    pos.X=21; pos.Y++; SCCP; printf("to swap the columns with the largest sum of elements and");
    pos.X=21; pos.Y++; SCCP; printf("the least amount of elements");
    pos.X=21; pos.Y++; SCCP; printf("to exit");
}

void rotateCW180(int size, float mat[size][size]){
float a[size][size];
int i, j;
for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            a[i][j]=mat[size-1-i][size-1-j];
        }
}
for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            mat[i][j]=a[i][j];
        }
}
}

void change(int size, float mat[size][size], int indexl, int indexc, float val){
    mat[indexc][indexl] = val;
}

void hor(int size, float mat[size][size]){
float a[size][size];
int i, j;
for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            a[i][j]=mat[size-1-i][j];
        }
}
for (i=0; i<size; i++){
        for (j=0; j<size; j++){
            mat[i][j]=a[i][j];
        }
}
}

void secdia(int size, float mat[size][size]){
float a[size][size];
int c, l;
for (l=0; l<size; l++){
        for (c=0; c<size; c++){
            a[c][l]=mat[size-1-l][size-1-c];
        }
}
for (c=0; c<size; c++){
        for (l=0; l<size; l++){
            mat[c][l]=a[c][l];
        }
}
}

float sumall(int size, float mat[size][size]){
int i, col;
float result=0, result1=0;
for(col=0; col<size; col++){
for (i=0; i<size; i++){
    result += *( *(mat+col) + i);
}
result1 += result;
}
return result1;
}

float sumcol(int size, float mat[size][size], int col){
int i;
float result=0;
for (i=0; i<size; i++){
    result += *( *(mat+col) + i);
}
return result;
}

float sumund(int size, float mat[size][size]){
int c, l;
float result=0;
for (c=0; c<size; c++){
        for (l=0; l<c+1; l++){
            result += mat[l][c];
        }
}
return result;
}

void min1max1(int size, float mat[size][size]){
int c, l, minil=0, minic=0, maxil=0, maxic=0;
float min=mat[0][0];
float max=mat[0][0];

for (c=0; c<size; c++){
        for (l=0; l<size; l++){
           if (min>mat[c][l]){
            min = mat[c][l];
            minil=l; minic=c;
           }
}
}
for (c=0; c<size; c++){
        for (l=0; l<size; l++){
           if (max<mat[c][l]){
            max = mat[c][l];
            maxil=l; maxic=c;
           }
}
}
mat[minic][minil]=max;
mat[maxic][maxil]=min;

int i,j;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
system("cls");
showzone(size);
COORD pos;
color_default;
pos.X=2; pos.Y=2; SCCP;
for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        if(i==maxil&&j==maxic){
            SetConsoleTextAttribute(hConsole, 10);
        }
        if(i==minil&&j==minic){
            SetConsoleTextAttribute(hConsole, 12);
        }
        printf("%.1f", *( *(mat+j) + i));
        pos.X=pos.X+6; pos.Y; SCCP;
        color_default;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
}
}

void minlmaxl(int size, float mat[size][size]){
int c, l, minil=size-1, minic=size-1, maxil=size-1, maxic=size-1;
float min=mat[size-1][size-1];
float max=mat[size-1][size-1];

for (c=size-1; c>=0; c--){
        for (l=size-1; l>=0; l--){
           if (min>mat[c][l]){
            min = mat[c][l];
            minil=l; minic=c;
           }
}
}
for (c=size-1; c>=0; c--){
        for (l=size-1; l>=0; l--){
           if (max<mat[c][l]){
            max = mat[c][l];
            maxil=l; maxic=c;
           }
}
}
mat[minic][minil]=max;
mat[maxic][maxil]=min;

int i,j;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
system("cls");
showzone(size);
COORD pos;
color_default;
pos.X=2; pos.Y=2; SCCP;
for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        if(i==maxil&&j==maxic){
            SetConsoleTextAttribute(hConsole, 10);
        }
        if(i==minil&&j==minic){
            SetConsoleTextAttribute(hConsole, 12);
        }
        printf("%.1f", *( *(mat+j) + i));
        pos.X=pos.X+6; pos.Y; SCCP;
        color_default;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
}
}

void cmcm(int size, float mat[size][size]){
int i, j, mini = 0, maxi = 0;
float sum=0, min=0, max=0;
for(i=0; i<size; i++){
    max += *( *(mat)+i);
}
min = max;

for(j=0; j<size; j++){
    sum = 0;
    for(i=0; i<size; i++){
        sum += *( *(mat+j) + i);
    }
    if (sum<min){
            min = sum;
            mini = j;
        }
        if (sum>max){
            max = sum;
            maxi = j;
        }
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
system("cls");
showzone(size);

COORD pos;
color_default;
pos.X=2; pos.Y=2; SCCP;
for(i=0; i<size; i++){
for(j=0; j<size; j++){
    if (j == mini){
        SetConsoleTextAttribute(hConsole, 12);
    }
    if (j==maxi){
        SetConsoleTextAttribute(hConsole, 10);
    }
    printf("%.1f", *( *(mat+j) + i));
    pos.X=pos.X+6; pos.Y; SCCP;
    color_default;
}
pos.Y=pos.Y+2, pos.X=2; SCCP;
}

pos.X=0; pos.Y=size*2+4; SCCP;

SetConsoleTextAttribute(hConsole, 10);
printf("Max sum = %f\n", max);
SetConsoleTextAttribute(hConsole, 12);
printf("Min sum = %f\n\n", min);
color_default;
}
