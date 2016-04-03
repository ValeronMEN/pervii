#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "drunkard.h"
#include "queue.h"

void drunkard(){
    int i;
    puts("Drunkard is started");

    //for 2 players, 36 cards
    srand(time(NULL));

    struct_c deck[36];
    int strokeman = rand() % 2;

    deck_fill_36(deck);

    queue_t * player = queue_new();
    queue_t * ai = queue_new();

    i=0;
    while(i<36){
        queue_enqueue(player, deck[i]);
        i++;
        queue_enqueue(ai, deck[i]);
        i++;
    }

    queue_view(player);
    queue_view(ai);

    puts("Drunkard finished");

    return;
}
