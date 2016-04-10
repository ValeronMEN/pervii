#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "witch.h"

void witch(){
    puts("Witch is started");

    int i;
    srand(time(NULL));

    //for 2 players
    struct_c deck[36];
    deck_fill_36(deck);

    list_t * player = list_new();
    list_t * ai = list_new();

    list_t * firstplayer = ai;
    list_t * secondplayer = player;

    int strokeman = rand() % 2;
    if (strokeman==1){
        firstplayer = player;
        secondplayer = ai;
    }
    printf("Result of strokeman is %i\n", strokeman);

    i = 0;
    while(i<36){
        list_add(firstplayer, deck[i], 0);
        i++;
        list_add(secondplayer, deck[i], 0);
        i++;
    }

    list_view(firstplayer);
    puts("");
    list_view(secondplayer);

    //int choice;
    //if(*firstplaye==*ai){
        //choice = rand() %
    //}

    //while(kbhit()==0){

    //}

    puts("Witch finished");
}
