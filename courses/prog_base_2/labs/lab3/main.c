#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>

#include "roulette.h"

static void newRoulette_void_zeroCount(void **state){
    roulette_t * myroulette = roulette_new();
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_OK);
    roulette_free(myroulette);
}

static void subsPlayers_11players_overflow(void **state){
    roulette_t * myroulette = roulette_new();
    int i;
    for(i=0; i<11; i++){
        player_new(myroulette, "Player");
    }
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_OVERFLOW);
    roulette_free(myroulette);
}

static void randomizer_void_empty(void **state){
    roulette_t * myroulette = roulette_new();
    roulette_randomizer(myroulette, 0, 0, 0, " ");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_EMPTY);
    roulette_free(myroulette);
}

static void randomizer03_3differentValues_03status(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 1, 2, 3, " ");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_03);
    roulette_free(myroulette);
}

static void randomizer23_2sameValues_23status(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 1, 1, 3, " ");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_23);
    roulette_free(myroulette);
}

static void randomizer33_3sameValues_33status(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 1, 1, 1, " ");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_33);
    roulette_free(myroulette);
}

static void randomizerJackpot_3valuesOf7_jackpotStatus(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 7, 7, 7, " ");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_JACKPOT);
    roulette_free(myroulette);
}

static void randomizer03_3differentValues_playerIncluded03status(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 1, 2, 3, "Unlock");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_PLAYER_03);
    roulette_free(myroulette);
}

static void randomizer23_2sameValues_playerIncluded23status(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 1, 1, 3, "Unlock");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_PLAYER_23);
    roulette_free(myroulette);
}

static void randomizer33_3sameValues_playerIncluded33status(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    administrator_new(myroulette, "Vadim");
    roulette_randomizer(myroulette, 1, 1, 1, "Unlock");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_PLAYER_33);
    roulette_free(myroulette);
}

static void randomizerJackpot_3valuesOf7_playerIncludedjackpotStatus(void **state){
    roulette_t * myroulette = roulette_new();
    player_new(myroulette, "Player");
    roulette_randomizer(myroulette, 7, 7, 7, "Unlock");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_PLAYER_JACKPOT);
    roulette_free(myroulette);
}

static void randomizerJackpot_3valuesOf7_pressIncludedjackpotStatus(void **state){
    roulette_t * myroulette = roulette_new();
    press_new(myroulette, "Times");
    roulette_randomizer(myroulette, 7, 7, 7, "Unlock");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_PRESS_INCLUDED);
    roulette_free(myroulette);
}

static void randomizerJackpot_3valuesOf7_administratorIncludedjackpotStatus(void **state){
    roulette_t * myroulette = roulette_new();
    administrator_new(myroulette, "Vadim");
    roulette_randomizer(myroulette, 7, 7, 7, "Unlock");
    assert_int_equal(roulette_getstatus(myroulette), ROULETTE_ADMINISTRATOR_INCLUDED);
    roulette_free(myroulette);
}

int main(){
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(newRoulette_void_zeroCount),
        cmocka_unit_test(subsPlayers_11players_overflow),
        cmocka_unit_test(randomizer_void_empty),
        cmocka_unit_test(randomizer03_3differentValues_03status),
        cmocka_unit_test(randomizer23_2sameValues_23status),
        cmocka_unit_test(randomizer33_3sameValues_33status),
        cmocka_unit_test(randomizerJackpot_3valuesOf7_jackpotStatus),
        cmocka_unit_test(randomizer03_3differentValues_playerIncluded03status),
        cmocka_unit_test(randomizer23_2sameValues_playerIncluded23status),
        cmocka_unit_test(randomizer33_3sameValues_playerIncluded33status),
        cmocka_unit_test(randomizerJackpot_3valuesOf7_playerIncludedjackpotStatus),
        cmocka_unit_test(randomizerJackpot_3valuesOf7_pressIncludedjackpotStatus),
        cmocka_unit_test(randomizerJackpot_3valuesOf7_administratorIncludedjackpotStatus),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
int main(){
    srand(time(NULL));
    printf("Hello player! Type something to play\n\n");

    while(1){
        getch();
        roulette_t * myroulette = roulette_new();

        player_new(myroulette, "Player");
        administrator_new(myroulette, "Vadim");
        press_new(myroulette, "Times");

        roulette_randomizer(myroulette, 0, 0, 0, "Unlock");
        puts("");

        roulette_randomizer(myroulette, 2, 1, 7);
        puts("");
        roulette_randomizer(myroulette, 5, 6, 6);
        puts("");
        roulette_randomizer(myroulette, 4, 4, 4);
        puts("");
        roulette_randomizer(myroulette, 7, 7, 7);
        puts("");

        roulette_free(myroulette);
    }

    return 0;
}
*/
