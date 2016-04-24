#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#include "witch.h"

void witch(){
    puts("Witch is started\n");
    int Xval = QUEEN;
    int Xsuit = SPADE;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

    int i = 0;
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
                if(ai->deck[i].value==ai->deck[j].value&&i!=j){
                    if ((ai->deck[i].value==Xval&&ai->deck[i].suit==Xsuit)||(ai->deck[j].value==Xval&&ai->deck[j].suit==Xsuit)){
                        continue;
                    }
                    if (j>i){
                        j--;
                    }
                    deck[n] = list_sub(ai, i);
                    n++;
                    deck[n] = list_sub(ai, j);
                    n++;
                    goto metka; //output of 2 loops
                }
            }
        }
        metka:
        //2 cards to out from player
        color_disco;
        puts("");
        list_view(player);
        while(1){
            printf("\nPrint 2 indexes of ecvivalent values of cards or -1 to exit\n");
            scanf("%i", &i);
            scanf("%i", &j);
            if (i==-1||j==-1){
                break;
            }
            if(player->deck[i].value==player->deck[j].value&&i!=j){
                if ((player->deck[i].value==Xval&&player->deck[i].suit==Xsuit)||(player->deck[j].value==Xval&&player->deck[j].suit==Xsuit)){
                    continue;
                }
                if (j>i){
                    j--;
                }
                deck[n] = list_sub(player, i);
                n++;
                deck[n] = list_sub(player, j);
                n++;
                break;
            }
            else {
                printf("Failed indexes!\n");
            }
        }
        color_default;
        list_view(player);
        puts("\n*******");
        list_view(ai);

        //finish check
        if (ai->size==0){
            printf("You lose\n");
            break;
        }
        if (player->size==0){
            printf("You win!\n");
            break;
        }

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
        puts("\n*******");
        list_view(ai);
    }

    puts("\nWitch finished");
}
