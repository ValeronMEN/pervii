#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "witch.h"

void witch(){
    puts("Witch is started");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int i;
    srand(time(NULL));

    //for 2 players
    struct_c deck[36];
    deck_fill_36(deck);

    list_t * player = list_new();
    list_t * ai = list_new_ai();

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
    deck_null_36(deck);

    list_view(firstplayer);
    puts("");
    list_view(secondplayer);

    int choice, j, n=0;
    list_t * temp;
    struct_c card;

    while(1){
        //2 cards to out from ai
        for(i=0; i<ai->size; i++){
            for(j=0; j<ai->size; j++){
                if (i==j){
                    continue;
                }
                if(ai->deck[i].value==ai->deck[j].value){
                    deck[n] = list_sub(ai, i);
                    n++;
                    deck[n] = list_sub(ai, j);
                    n++;
                    break;
                }
            }
        }
        //2 cards to out from player
        color_disco;
        puts("");
        list_view(player);
        while(1){
            color_disco;
            printf("\nPrint 2 indexes of ecvivalent values of cards\n");
            scanf("%i", &i);
            scanf("%i", &j);
            color_default;
            if (i==j){
                printf("Bad indexes!");
                continue;
            }
            if(player->deck[i].value==player->deck[j].value){
                deck[n] = list_sub(player, i);
                n++;
                deck[n] = list_sub(player, j);
                n++;
                break;
            }
        }
        color_default;
        //ai 1
        if(firstplayer->ai==1){
            choice = rand() % list_getcount(secondplayer);
            card = list_sub(secondplayer, choice);
            list_add(firstplayer, card, 0);
        }
        //player
        color_disco;
        printf("\nPrint your choice\n");
        scanf("%i", &choice);
        color_default;
        card = list_sub(ai, choice);
        list_add(player, card, 0);
        //ai 2
        if (secondplayer->ai==1){
            choice = rand() % list_getcount(firstplayer);
            card = list_sub(firstplayer, choice);
            list_add(secondplayer, card, 0);
        }
        //swap
        temp = firstplayer;
        firstplayer = secondplayer;
        secondplayer = temp;

        list_view(player);
        list_view(ai);
    }

    puts("\nWitch finished");
}
