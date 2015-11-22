#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <windows.h>

#define color_error SetConsoleTextAttribute(hConsole, BACKGROUND_RED)
#define SCCP SetConsoleCursorPosition(hConsole, pos)
#define color_default SetConsoleTextAttribute(hConsole, 7)

void showzone(int size){
int i, j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE);
    pos.X=0; pos.Y=0; SCCP;
    for (i=0; i<6*size+4; i++){
        printf("*");
    }
    pos.X=0; pos.Y=1; SCCP;
    for(i=0; i<size*2+1; i++){
        printf("|");
        for(j=1; j<6*size+3; j++)
            printf(" ");
        pos.Y++; pos.X; SCCP;
    }
    pos.X=6*size+3; pos.Y=1; SCCP;
    for(i=0; i<size*2+1; i++){
        printf("|");
        pos.Y++; pos.X; SCCP;
    }
    pos.X=0; pos.Y=size*2+2; SCCP;
    for (i=0; i<6*size+4; i++){
        printf("*");
    }
}

void printmatrix(int size, float mat[size][size]){
    int i,j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    pos.X=2; pos.Y=2; SCCP;
    for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        printf("%.1f", mat[i][j]);
        pos.X=pos.X+6; pos.Y; SCCP;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
    }
}

void printmatrixsum(int size, float mat[size][size]){
    int i,j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    pos.X=2; pos.Y=2; SCCP;
    for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        printf("%.1f", mat[i][j]);
        pos.X=pos.X+6; pos.Y; SCCP;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
    }
}

void printmatrixcol(int size, float mat[size][size], int col){
    int i,j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    color_default;
    pos.X=2; pos.Y=2; SCCP;
    for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        if (i==col){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        }
        printf("%.1f", mat[i][j]);
        pos.X=pos.X+6; pos.Y; SCCP;
        color_default;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
    }
}

void printmatrixch(int size, float mat[size][size], int indexl, int indexc){
    int i,j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    color_default;
    pos.X=2; pos.Y=2; SCCP;
    for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        if (i==indexc&&j==indexl){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        }
        printf("%.1f", mat[i][j]);
        pos.X=pos.X+6; pos.Y; SCCP;
        color_default;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
    }
}

void printmatrixund(int size, float mat[size][size]){
    int i,j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    color_default;
    pos.X=2; pos.Y=2; SCCP;
    for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        if (i<j+1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        }
        printf("%.1f", mat[i][j]);
        pos.X=pos.X+6; pos.Y; SCCP;
        color_default;
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
    }
}

void printmatrixsec(int size, float mat[size][size]){
    int i,j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

   SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    pos.X=2; pos.Y=2; SCCP;
    for(j=0; j<size; j++){
    for(i=0; i<size; i++){
        if ((size-1-i)==(j)){
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        printf("%.1f", mat[i][j]);
        pos.X=pos.X+6; pos.Y; SCCP;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    pos.Y=pos.Y+2, pos.X=2; SCCP;
    }
}
