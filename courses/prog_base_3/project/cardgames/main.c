#include <stdio.h>
#include <stdlib.h>

#include "drunkard.h"

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