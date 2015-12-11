#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define SCCP SetConsoleCursorPosition(hConsole, pos)
#define color_default SetConsoleTextAttribute(hConsole, 7)
#define color_disco SetConsoleTextAttribute(hConsole, 13)
#define color_elka SetConsoleTextAttribute(hConsole, 42)
#define color_error SetConsoleTextAttribute(hConsole, 12)
#define color_edit SetConsoleTextAttribute(hConsole, 11)
#define color_mem SetConsoleTextAttribute(hConsole, 9)
#define color_play SetConsoleTextAttribute(hConsole, 10)

struct Notes{
    char name;
    int freq;
    int oktava;
};

struct Melody{
    int index;
    char title[100];
    char composer[100];
    char playlist[100];
    char plot[200];
};

void printmelstruct(struct Melody *struct1){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("Index is: ");
    SetConsoleTextAttribute(hConsole, 163); //6
    printf("%i\n", struct1->index);
    color_default;
    printf("Title is: ");
    SetConsoleTextAttribute(hConsole, 30); //30 87 154 163 92 9 11
    printf("%s", struct1->title);
    color_default;
    printf("Composer is: ");
    SetConsoleTextAttribute(hConsole, 10); //10
    printf("%s", struct1->composer);
    color_default;
    printf("Playlist is: ");
    SetConsoleTextAttribute(hConsole, 11); //6
    printf("%s", struct1->playlist);
    color_default;
    printf("Notes are: ");
    SetConsoleTextAttribute(hConsole, 163); //6
    printf("%s\n", struct1->plot);
    color_default;
}

void printnotesstruct(struct Notes *struct1){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("Name is: ");
    SetConsoleTextAttribute(hConsole, 87); //30 87 154 163 92 9 11
    printf("%c\n", struct1->name);
    color_default;
    printf("Frequency is: ");
    SetConsoleTextAttribute(hConsole, 154); //10
    printf("%i\n", struct1->freq);
    color_default;
    printf("Oktava is: ");
    SetConsoleTextAttribute(hConsole, 9); //6
    printf("%i\n\n", struct1->oktava);
    color_default;
}

void pianino (int freq, char l, struct Notes *struct1){
        switch(l){
                case 'a':
                Beep((struct1->freq), freq); break;
                case 's':
                Beep(*((&(struct1->freq)+3)),freq); break;
                case 'd':
                Beep(*((&(struct1->freq)+6)),freq); break;
                case 'f':
                Beep(*((&(struct1->freq)+9)),freq); break;
                case 'g':
                Beep(*((&(struct1->freq)+12)),freq); break;
                case 'h':
                Beep(*((&(struct1->freq)+15)),freq); break;
                case 'j':
                Beep(*((&(struct1->freq)+18)),freq); break;
                case 'k':
                Beep(*((&(struct1->freq)+21)),freq); break;
        }
}

void pianino2 (int freq, char l, struct Notes *struct1){
        switch(l){
                case 'C':
                Beep((struct1->freq), freq); break;
                case 'D':
                Beep(*((&(struct1->freq)+3)),freq); break;
                case 'E':
                Beep(*((&(struct1->freq)+6)),freq); break;
                case 'F':
                Beep(*((&(struct1->freq)+9)),freq); break;
                case 'G':
                Beep(*((&(struct1->freq)+12)),freq); break;
                case 'A':
                Beep(*((&(struct1->freq)+15)),freq); break;
                case 'B':
                Beep(*((&(struct1->freq)+18)),freq); break;
                case 'S':
                Beep(*((&(struct1->freq)+21)),freq); break;
                case '?':
                Sleep(250); break;
        }
}

void recordfile(int amount, struct Melody arr[amount]){
    FILE* fp;
    int j;
    fp = fopen("input.txt", "w");

    fprintf(fp, "%i\n", amount);
    for(j=0; j<amount; j++){
        fprintf(fp, "%i\n", arr[j].index);
        fputs(&(arr[j].title), fp);
        fputs(&(arr[j].composer), fp);
        fputs(&(arr[j].playlist), fp);
        fputs(&(arr[j].plot), fp);
        fputs("\n", fp);
    }

    fclose(fp);
}

char pianino3 (int freq, char l2, struct Notes *struct1){
switch(l2){
    case 'a':
    Beep((struct1->freq), freq); return 'C'; break;
    case 's':
    Beep(*((&(struct1->freq)+3)),freq); return 'D'; break;
    case 'd':
    Beep(*((&(struct1->freq)+6)),freq); return 'E'; break;
    case 'f':
    Beep(*((&(struct1->freq)+9)),freq); return 'F'; break;
    case 'g':
    Beep(*((&(struct1->freq)+12)),freq); return 'G'; break;
    case 'h':
    Beep(*((&(struct1->freq)+15)),freq); return 'A'; break;
    case 'j':
    Beep(*((&(struct1->freq)+18)),freq); return 'B'; break;
    case 'k':
    Beep(*((&(struct1->freq)+21)),freq); return 'S'; break;
    default: return '?'; break;
}
}
