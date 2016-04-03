#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "drunkard.h"
#include "standard.h"

/*
void drunkard_rand(int * player, int * ai){
    int random_card = 0;
    return;
}
*/

void drunkard(){
    puts("Drunkard is started");

    //for 2 players, 36 cards
    srand(time(NULL));

    struct_c deck[36];
    coloda_fill_36(deck);

    int i;

    for(i=0; i<36; i++){
        printf("Val: %i, suit: %i\n", deck[i].value, deck[i].suit);
    }

    //struct_c player[18];
    //struct_c ai[18];
    //drunkard_rand(player, ai);

    return;
}
