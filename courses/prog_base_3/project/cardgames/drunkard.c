#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "drunkard.h"
#include "queue.h"

void drunkard(){
    puts("Drunkard is started");

    //for 2 players, 36 cards
    srand(time(NULL));

    struct_c deck[36];
    struct_c player[36];
    struct_c ai[36];
    int strokeman = rand() % 2;

    deck_fill_36(deck);
    deck_null_36(player);
    deck_null_36(ai);
    //drunkard_halfdistribution(player, ai);

    //initQueueArray(player);

    puts("Drunkard finished");

    return;
}
