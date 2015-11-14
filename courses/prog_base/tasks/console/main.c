#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SCCP SetConsoleCursorPosition(hConsole, pos)
#define S Sleep(mil)

int main()
{
    int i;
    const long mil = 15;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=0; pos.Y=0; color(pos.X, pos.Y); printf("*");

    for (i=0; i<12; i++){
      S; pos.Y; pos.X++; SCCP; color(pos.X, pos.Y); printf("*");
      while(pos.X!=0){S; pos.Y++; pos.X--; SCCP; color(pos.X, pos.Y); printf("*");}
      S; pos.X; pos.Y++; SCCP; color(pos.X, pos.Y); printf("*");
      while(pos.Y!=0){S; pos.X++; pos.Y--; SCCP; color(pos.X, pos.Y); printf("*");}
    }

    for (i=0; i<27; i++){
      S; pos.Y; pos.X++; SCCP; color(pos.X, pos.Y); printf("*");
      while(pos.Y!=24){S; pos.Y++; pos.X--; SCCP; color(pos.X, pos.Y); printf("*");}
      S; pos.Y; pos.X++; SCCP; color(pos.X, pos.Y); printf("*");
      while(pos.Y!=0){S; pos.X++; pos.Y--; SCCP; color(pos.X, pos.Y); printf("*");}
    }

    S; pos.X=79; pos.Y=0; color(pos.X, pos.Y); printf("*");

    for (i=0; i<12; i++){
      while(pos.Y!=24){S; pos.Y++; pos.X--; SCCP; color(pos.X, pos.Y); printf("*");}
      S; pos.Y; pos.X++; SCCP; color(pos.X, pos.Y); printf("*");
      while(pos.X!=79){S; pos.X++; pos.Y--; SCCP; color(pos.X, pos.Y); printf("*");}
      S; pos.X; pos.Y++; SCCP; color(pos.X, pos.Y); printf("*");
    }

pos.X=0; pos.Y=26; SCCP;
return 0;
}

void color(int x, int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(y==x||y==(x-55)){
       SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
    } else if(x>y&&x<(y+55)){
       SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE);
    } else {
       SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
    }
}
