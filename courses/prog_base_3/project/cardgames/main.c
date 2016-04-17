#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "drunkard.h"
#include "witch.h"

int main()
{
    char gamecode = 's';

    printf("Hi, player. Choose game to play!\n");
    while(gamecode!='e'){
        switch (gamecode) {
        case '1':
           //Blackjack
           break;
        case '2':
           //Witch
           witch();
           break;
        case '3':
           //Chicken
           break;
        case '4':
           //Pig
           break;
        case '5':
           //Drunkard
           drunkard();
           break;
        default: break;
        }
        gamecode = getch();
    }

    return 0;
}
