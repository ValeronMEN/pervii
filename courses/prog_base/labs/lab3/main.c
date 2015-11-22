#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "advanced.h"
#include "functions.h"

#define SCCP SetConsoleCursorPosition(hConsole, pos)
#define color_error SetConsoleTextAttribute(hConsole, BACKGROUND_RED)
#define color_default SetConsoleTextAttribute(hConsole, 7)
#define standard system("cls"); showzone(size); printmatrix(size, mat); color_default
#define Error standard; pos.X=0; pos.Y=size*2+4; SCCP; color_error; printf("Error: Invalid command."); color_default; printf(" Enter command again. For help menu use command !help.\n"); printf(">> "); SetConsoleTextAttribute(hConsole, 13); scanf("%s", command); continue

int main()
{
    int size;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    printf("Enter matrix size. Size can be [0..12].\n");
    printf(">> ");
    scanf("%i", &size);
    if (size>12||size<0){
        puts("");
        color_error;
        printf("Error: Invalid matrix size.\n");
        color_default;
        return 1;
    }

    system("cls");
    pos.X=0; pos.Y=0; SCCP;

    //first matrix

    float mat[size][size];
    char *command;
    int i;

    myrandom(size, mat, -10, 10);

    //work zone
    int g=0, d1, d2, indexl, indexc, col;
    float val, sum;
    float * min;
    float * max;

    standard;
    pos.X=0; pos.Y=size*2+4; SCCP;
    printf("Enter command. For help menu use command !help.\n");
    printf(">> ");
    SetConsoleTextAttribute(hConsole, 13);
    scanf("%s", command);

    while(g==0){
    standard;
    i=0;
    while(*(command+i)==' '){
            i++;
    }
     if (*(command+i)=='!'){
        if (*(command+i+1)=='h'&&*(command+i+2)=='e'&&*(command+i+3)=='l'&&*(command+i+4)=='p'){
                standard;
                help(size);
                pos.X=0; pos.Y=size*2+24; SCCP;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                continue;
        }
        if (*(command+i+1)=='e'&&*(command+i+2)=='x'&&*(command+i+3)=='i'&&*(command+i+4)=='t'){
                break;
        }
        if (*(command+i+1)=='r'&&*(command+i+2)=='a'&&*(command+i+3)=='n'&&*(command+i+4)=='d'&&*(command+i+5)=='o'&&*(command+i+6)=='m'){
                standard;
                pos.X=0; pos.Y=size*2+4; SCCP;
                printf("Enter first limit of random function ([-99..99]).\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 10);
                scanf("%i", &d1);
                color_default;
                puts("");
                printf("Enter last limit of random function ([-99..99]).\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 10);
                scanf("%i", &d2);
                if (d1<=d2&&d1<=99&&d2<=99&&d1>=-99&&d2>=-99){
                   myrandom(size, mat, d1, d2);
                   standard;
                   pos.X=0; pos.Y=size*2+4; SCCP;
                   printf("Enter command. For help menu use command !help.\n");
                   printf(">> ");
                   SetConsoleTextAttribute(hConsole, 13);
                   scanf("%s", command);
                   continue;
                }
                else
                { Error; }

        }
        if (*(command+i+1)=='r'&&*(command+i+2)=='o'&&*(command+i+3)=='t'&&*(command+i+4)=='a'&&*(command+i+5)=='t'&&*(command+i+6)=='e'){
                standard;
                rotateCW180(size, mat);
                printmatrix(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                standard;
                continue;
        }
        if (*(command+i+1)=='n'&&*(command+i+2)=='u'&&*(command+i+3)=='l'&&*(command+i+4)=='l'){
                standard;
                myrandom(size, mat, 0, 0);
                printmatrix(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                standard;
                continue;
        }
        if (*(command+i+1)=='c'&&*(command+i+2)=='h'&&*(command+i+3)=='a'&&*(command+i+4)=='n'&&*(command+i+5)=='g'&&*(command+i+6)=='e'){
                standard;
                pos.X=0; pos.Y=size*2+4; SCCP;
                printf("Enter line index of element.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 10);
                scanf("%i", &indexl);
                color_default;
                puts("");
                printf("Enter column index of element.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 10);
                scanf("%i", &indexc);
                color_default;
                puts("");
                printf("Enter yor value for this element[-99..99].\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 10);
                scanf("%f", &val);
                if (val<=99&&val>=-99&&indexl<size&&indexc<size&&indexl>=0&&indexc>=0){
                   change(size, mat, indexl, indexc, val);
                   system("cls"); showzone(size);
                   printmatrixch(size, mat, indexl, indexc);
                   pos.X=0; pos.Y=size*2+4; SCCP;
                   printf("Enter command. For help menu use command !help.\n");
                   printf(">> ");
                   SetConsoleTextAttribute(hConsole, 13);
                   scanf("%s", command);
                   continue;
                }
                else
                { Error; }
               }
        if (*(command+i+1)=='h'&&*(command+i+2)=='o'&&*(command+i+3)=='r'){
                standard;
                hor(size, mat);
                printmatrix(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                standard;
                continue;
        }
        if (*(command+i+1)=='s'&&*(command+i+2)=='e'&&*(command+i+3)=='c'&&*(command+i+4)=='d'&&*(command+i+5)=='i'&&*(command+i+6)=='a'){
                standard;
                secdia(size, mat);
                printmatrix(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                standard;
                continue;
        }
        if (*(command+i+1)=='s'&&*(command+i+2)=='u'&&*(command+i+3)=='m'&&*(command+i+4)=='a'&&*(command+i+5)=='l'&&*(command+i+6)=='l'){
                standard;
                sum = sumall(size, mat);
                printmatrixsum(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                SetConsoleTextAttribute(hConsole, 12);
                printf("The sum of elements of a matrix: %f\n\n", sum);
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                standard;
                continue;
        }
        if (*(command+i+1)=='s'&&*(command+i+2)=='u'&&*(command+i+3)=='m'&&*(command+i+4)=='c'&&*(command+i+5)=='o'&&*(command+i+6)=='l'){
                standard;
                pos.X=0; pos.Y=size*2+4; SCCP;
                printf("Enter column:\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 10);
                scanf("%i", &col);
                if (col>=0&&col<size){
                   sum = sumcol(size, mat, col);
                   system("cls");
                   showzone(size);
                   printmatrixcol(size, mat, col);
                   pos.X=0; pos.Y=size*2+4; SCCP;
                   SetConsoleTextAttribute(hConsole, 12);
                   printf("The sum of elements of the column of a matrix: %f\n\n", sum);
                   color_default;
                   printf("Enter command. For help menu use command !help.\n");
                   printf(">> ");
                   SetConsoleTextAttribute(hConsole, 13);
                   scanf("%s", command);
                   continue;
                }
                else
                { Error; }
        }
        if (*(command+i+1)=='s'&&*(command+i+2)=='u'&&*(command+i+3)=='m'&&*(command+i+4)=='u'&&*(command+i+5)=='n'&&*(command+i+6)=='d'){
                standard;
                sum = sumund(size, mat);
                system("cls");
                showzone(size);
                printmatrixund(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                SetConsoleTextAttribute(hConsole, 12);
                printf("The sum of elements of a zone: %f\n\n", sum);
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                continue;
        }
        if (*(command+i+1)=='m'&&*(command+i+2)=='i'&&*(command+i+3)=='n'&&*(command+i+4)=='1'&&*(command+i+5)=='m'&&*(command+i+6)=='a'&&*(command+i+7)=='x'&&*(command+i+8)=='1'){
                standard;
                min1max1(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                continue;
        }
        if (*(command+i+1)=='m'&&*(command+i+2)=='i'&&*(command+i+3)=='n'&&*(command+i+4)=='l'&&*(command+i+5)=='m'&&*(command+i+6)=='a'&&*(command+i+7)=='x'&&*(command+i+8)=='l'){
                standard;
                minlmaxl(size, mat);
                pos.X=0; pos.Y=size*2+4; SCCP;
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                continue;
        }
        if (*(command+i+1)=='c'&&*(command+i+2)=='m'&&*(command+i+3)=='c'&&*(command+i+4)=='m'){
                standard;
                cmcm(size, mat);
                color_default;
                printf("Enter command. For help menu use command !help.\n");
                printf(">> ");
                SetConsoleTextAttribute(hConsole, 13);
                scanf("%s", command);
                continue;
        }
        else {  Error; }
        }
    else { Error; }
    }
pos.X=0; pos.Y=size*2+3; SCCP;
return 0;
}

