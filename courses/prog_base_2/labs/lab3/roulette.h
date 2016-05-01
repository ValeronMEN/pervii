#ifndef ROULETTE_H_INCLUDED
#define ROULETTE_H_INCLUDED

#define MAX_SUBSCRIBERS_SIZE 10
#define MAX_NAME_SIZE 100

typedef struct roulette_s roulette_t;
typedef struct user_s user_t;

typedef void (*MyCallback)(const char *, const char *, roulette_t *);

typedef enum roulette_status{
    ROULETTE_OK,
    ROULETTE_OVERFLOW,
    ROULETTE_EMPTY,
    ROULETTE_03,
    ROULETTE_23,
    ROULETTE_33,
    ROULETTE_JACKPOT,
    ROULETTE_PLAYER_03,
    ROULETTE_PLAYER_23,
    ROULETTE_PLAYER_33,
    ROULETTE_PLAYER_JACKPOT,
    ROULETTE_PRESS_INCLUDED,
    ROULETTE_ADMINISTRATOR_INCLUDED,
} roulette_status;

roulette_t * roulette_new();
void roulette_free(roulette_t * self);
void roulette_randomizer(roulette_t * self, int, int, int, const char *);
roulette_status roulette_getstatus(roulette_t *);

void administrator_new(roulette_t * self, const char * name);
void player_new(roulette_t * self, const char * name);
void press_new(roulette_t * self, const char * name);

#endif // ROULETTE_H_INCLUDED
