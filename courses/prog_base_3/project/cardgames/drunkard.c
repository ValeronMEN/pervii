#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "drunkard.h"
#include "queue.h"

void drunkard(){
    int i;
    puts("Drunkard is started");

    //for 2 players, 36 cards
    srand(time(NULL));

    struct_c deck[36];
    deck_fill_36(deck);
    queue_t * player = queue_new();
    queue_t * ai = queue_new();

    //first stroke
    int strokeman = rand() % 2;
    queue_t * firstplayer = ai;
    queue_t * secondplayer = player;
    printf("Result of strokeman is %i\n", strokeman);
    if (strokeman == 0){
        firstplayer = player;
        secondplayer = ai;
    }

    i=0;
    while(i<36){
        queue_enqueue(firstplayer, deck[i]);
        i++;
        queue_enqueue(secondplayer, deck[i]);
        i++;
    }

    queue_view(firstplayer);
    queue_view(secondplayer);

    struct_c card1f, card1s, card2f, card2s, card3f, card3s;
    queue_t * temp;

    while(kbhit()==0){
        card1f = queue_dequeue(firstplayer);
        card1s = queue_dequeue(secondplayer);
        printf("\nCards\n");
        if (card1f.value>card1s.value){
            queue_enqueue(firstplayer, card1f);
            queue_enqueue(firstplayer, card1s);
        }
        if (card1f.value<card1s.value){
            queue_enqueue(secondplayer, card1f);
            queue_enqueue(secondplayer, card1s);
        }
        else{
            card2f = queue_dequeue(firstplayer);
            card2s = queue_dequeue(secondplayer);
            card3f = queue_dequeue(firstplayer);
            card3s = queue_dequeue(secondplayer);
            if (card3f.value>card3s.value){
                queue_enqueue(firstplayer, card1f);
                queue_enqueue(firstplayer, card1s);
                queue_enqueue(firstplayer, card2f);
                queue_enqueue(firstplayer, card2s);
                queue_enqueue(firstplayer, card3f);
                queue_enqueue(firstplayer, card3s);
            }
            if (card3f.value<card3s.value){
                queue_enqueue(secondplayer, card1f);
                queue_enqueue(secondplayer, card1s);
                queue_enqueue(secondplayer, card2f);
                queue_enqueue(secondplayer, card2s);
                queue_enqueue(secondplayer, card3f);
                queue_enqueue(secondplayer, card3s);
            }
            else{
                queue_enqueue(firstplayer, card1f);
                queue_enqueue(firstplayer, card1s);
                queue_enqueue(firstplayer, card2f);
                queue_enqueue(firstplayer, card2s);
                queue_enqueue(firstplayer, card3f);
                queue_enqueue(firstplayer, card3s);
            }
        }
        temp = firstplayer;
        firstplayer = secondplayer;
        secondplayer = temp;

        if (queue_getsize(firstplayer)==36||queue_getsize(secondplayer)==36){
            break;
        }
    }

    queue_view(firstplayer);
    puts("");
    queue_view(secondplayer);

    puts("Drunkard finished");

    return;
}
