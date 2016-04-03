#include <stdio.h>
#include <stdlib.h>

#include "standard.h"

void coloda_fill_36(struct_c * result){
    int i, j;
    int min = 6; //minimal card in deck

    struct_c deck[36];

    for (i=0; i<9; i++){
        deck[i].suit = HEART;
        deck[i].value = min+i;
    }
    for (i=9, j=0; i<18; i++, j++){
        deck[i].suit = DIAMOND;
        deck[i].value = min+j;
    }
    for (i=18, j=0; i<27; i++, j++){
        deck[i].suit = CLUB;
        deck[i].value = min+j;
    }
    for (i=27, j=0; i<36; i++, j++){
        deck[i].suit = SPADE;
        deck[i].value = min+j;
    }
    for(i=0; i<36; i++){
        printf("Val: %i, suit: %i\n", deck[i].value, deck[i].suit);
    }

    i=0;
    j=0;
    int stroke;

    while(i<36){
        stroke = rand() % 36;
        j=j+stroke;
        if (j>=36){
            j=j-36;
        }
        while(deck[j].value==EMPTY){
            j++;
            if (j>=36){
                j=j-36;
            }
        }
        (result+i)->value = deck[j].value;
        (result+i)->suit = deck[j].suit;
        deck[j].value = EMPTY;
        deck[j].suit = NOSUIT;
        i++;
    }
    return;
}
