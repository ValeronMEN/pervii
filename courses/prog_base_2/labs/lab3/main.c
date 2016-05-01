#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "roulette.h"

int main(){
    srand(time(NULL));
    printf("Hello player! Type something to play\n\n");

    while(1){
        getch();
        roulette_t * myroulette = roulette_new();

        player_new(myroulette, "Player");
        administrator_new(myroulette, "Vadim");
        press_new(myroulette, "Times");

        roulette_randomizer(myroulette, 0, 0, 0);
        puts("");

        /*
        roulette_randomizer(myroulette, 2, 1, 7);
        puts("");
        roulette_randomizer(myroulette, 5, 6, 6);
        puts("");
        roulette_randomizer(myroulette, 4, 4, 4);
        puts("");
        roulette_randomizer(myroulette, 7, 7, 7);
        puts("");
        */
        roulette_free(myroulette);
    }

    return 0;
}
