#ifndef ROULETTE_H_INCLUDED
#define ROULETTE_H_INCLUDED

#define MAX_SUBSCRIBERS_SIZE 10
#define MAX_NAME_SIZE 100

typedef void (*MyCallback)(const char *, const char *);

typedef struct roulette_s roulette_t;
typedef struct user_s user_t;

//methods

roulette_t * roulette_new();

void roulette_free(roulette_t * self);

void administrator_new(roulette_t * self, const char * name);
void player_new(roulette_t * self, const char * name);
void press_new(roulette_t * self, const char * name);

void player(const char * message, const char * name);
void administrator(const char * message, const char * name);
void press(const char * message, const char * name);

void roulette_randomizer(roulette_t * self, int, int, int);
void roulette_subs(roulette_t * self, void (*excb)(const char *, const char *), const char *);

#endif // ROULETTE_H_INCLUDED
