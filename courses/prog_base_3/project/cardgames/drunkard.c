#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <windows.h>
#include <conio.h>

#include "drunkard.h"

void check(queue_t * firstplayer, queue_t * secondplayer){
    queue_view(firstplayer);
    puts("");
    queue_view(secondplayer);
}

void drunkard(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
    //printf("Result of strokeman is %i\n", strokeman);
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

    check(firstplayer, secondplayer);

    struct_c card1f, card1s, card2f, card2s, card3f, card3s;
    queue_t * temp;

    while(kbhit()==0){
        card1f = queue_dequeue(firstplayer);
        card1s = queue_dequeue(secondplayer);
        color_disco;
        //printf("\nCards 1. %i-%i, 2. %i-%i\n", card1f.value, card1f.suit, card1s.value, card1s.suit);
        color_default;
        if (card1f.value>card1s.value){
            queue_enqueue(firstplayer, card1f);
            queue_enqueue(firstplayer, card1s);
            //check(firstplayer, secondplayer);
        }
        if (card1f.value<card1s.value){
            queue_enqueue(secondplayer, card1f);
            queue_enqueue(secondplayer, card1s);
            //check(firstplayer, secondplayer);
        }
        if (card1f.value==card1s.value){
            card2f = queue_dequeue(firstplayer);
            card2s = queue_dequeue(secondplayer);
            color_disco;
            //printf("\nCards 1. %i-%i, 2. %i-%i", card2f.value, card2f.suit, card2s.value, card2s.suit);
            color_default;
            if (card2f.value==0){
                queue_enqueue(secondplayer, card1f);
                queue_enqueue(secondplayer, card1s);
                queue_enqueue(secondplayer, card2s);
                //check(firstplayer, secondplayer);
            }
            if (card2s.value==0){
                queue_enqueue(firstplayer, card1f);
                queue_enqueue(firstplayer, card1s);
                queue_enqueue(firstplayer, card2f);
                //check(firstplayer, secondplayer);
            }
            if (card2f.value!=0&&card2s.value!=0){
                card3f = queue_dequeue(firstplayer);
                card3s = queue_dequeue(secondplayer);

                color_disco;
                //printf("\nCards 1. %i-%i, 2. %i-%i\n", card3f.value, card3f.suit, card3s.value, card3s.suit);
                color_default;
                if (card3f.value>card3s.value){
                    queue_enqueue(firstplayer, card1f);
                    queue_enqueue(firstplayer, card1s);
                    queue_enqueue(firstplayer, card2f);
                    queue_enqueue(firstplayer, card2s);
                    queue_enqueue(firstplayer, card3f);
                    queue_enqueue(firstplayer, card3s);
                    //check(firstplayer, secondplayer);
                }
                if (card3f.value<card3s.value){
                    queue_enqueue(secondplayer, card1f);
                    queue_enqueue(secondplayer, card1s);
                    queue_enqueue(secondplayer, card2f);
                    queue_enqueue(secondplayer, card2s);
                    queue_enqueue(secondplayer, card3f);
                    queue_enqueue(secondplayer, card3s);
                    //check(firstplayer, secondplayer);
                }
                if (card3f.value==card3s.value){
                    queue_enqueue(firstplayer, card1f);
                    queue_enqueue(firstplayer, card1s);
                    queue_enqueue(firstplayer, card2f);
                    queue_enqueue(firstplayer, card2s);
                    queue_enqueue(firstplayer, card3f);
                    queue_enqueue(firstplayer, card3s);
                    //check(firstplayer, secondplayer);
                }
            }
        }
        temp = firstplayer;
        firstplayer = secondplayer;
        secondplayer = temp;

        if (queue_getsize(firstplayer)==36||queue_getsize(secondplayer)==36){
            break;
        }
        //system("pause");
    }

    check(firstplayer, secondplayer);

    if(queue_getsize(player)==36){
        printf("You win!\n");
    }
    else{
        printf("You lose\n");
    }

    puts("Drunkard finished");
    return;
}
