#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roulette.h"

void player(const char * message, const char * name, roulette_t * self);
void administrator(const char * message, const char * name, roulette_t * self);
void press(const char * message, const char * name, roulette_t * self);
void roulette_subs(roulette_t * self, void (*excb)(const char *, const char *, roulette_t *), const char *);

struct roulette_s{
    int first;
    int second;
    int third;
    MyCallback cb[MAX_SUBSCRIBERS_SIZE];
    char names[MAX_NAME_SIZE][MAX_SUBSCRIBERS_SIZE];
    int size;
    roulette_status status;
};

roulette_t * roulette_new(){
    roulette_t * self = malloc(sizeof(struct roulette_s));
    self->first = 0;
    self->second = 0;
    self->third = 0;
    self->size = 0;
    self->status = ROULETTE_OK;
    return self;
}

void roulette_free(roulette_t * self){
    free(self);
}

void player(const char * message, const char * name, roulette_t * self){
    printf("%s, you have %s\n", name, message);
    if (strcmp(message, "0 / 3")==0){
        printf("I'm sorry, but you're not a winner :(\n");
        self->status = ROULETTE_PLAYER_03;
        return;
    }
    if (strcmp(message, "2 / 3")==0){
        printf("You're not a winner, but close to victory! :)\n");
        self->status = ROULETTE_PLAYER_23;
        return;
    }
    if (strcmp(message, "3 / 3")==0){
        printf("You're a winner! :D\n");
        self->status = ROULETTE_PLAYER_33;
        return;
    }
    if (strcmp(message, "Jackpot!")==0){
        printf("You're a super winner! :D\n");
        self->status = ROULETTE_PLAYER_JACKPOT;
        return;
    }
}

void administrator(const char * message, const char * name, roulette_t * self){
    if (strcmp(message, "Jackpot!")==0){
        printf("Administrator %s informed. He will come soon\n", name);
        self->status = ROULETTE_ADMINISTRATOR_INCLUDED;
        return;
    }
    else {
        return;
    }
}

void press(const char * message, const char * name, roulette_t * self){
    if (strcmp(message, "Jackpot!")==0){
        printf("Press '%s' informed. They will come soon\n", name);
        self->status = ROULETTE_PRESS_INCLUDED;
        return;
    }
    else {
        return;
    }
}

void administrator_new(roulette_t * self, const char * name){
    roulette_subs(self, administrator, name);
}

void player_new(roulette_t * self, const char * name){
    roulette_subs(self, player, name);
}

void press_new(roulette_t * self, const char * name){
    roulette_subs(self, press, name);
}

void roulette_subs(roulette_t * self, MyCallback excb, const char * name){
    if (self->size==MAX_SUBSCRIBERS_SIZE){
        printf("Subscribers overflow!\n");
        self->status = ROULETTE_OVERFLOW;
        return;
    }
    self->cb[self->size] = excb;
    strcpy(self->names[self->size], name);
    self->size++;
}

void roulette_randomizer(roulette_t * self, int a, int b, int c, const char * block){ //f function
    if (self->size == 0){
        self->status = ROULETTE_EMPTY;
        return;
    }
    if (a!=0&&b!=0&&c!=0){
        self->first = a;
        self->second = b;
        self->third = c;
    }
    else{
        self->first = rand() % 9 + 1;
        self->second = rand() % 9 + 1;
        self->third = rand() % 9 + 1;
    }

    printf("%i | %i | %i\n", self->first, self->second, self->third);

    int i;
    if (self->first==7&&self->second==7&&self->third==7){
        self->status = ROULETTE_JACKPOT;
        if (strcmp("Unlock", block)==1){
            return;
        }
        for (i=0; i<self->size; i++){
            self->cb[i]("Jackpot!", self->names[i], self);
        }
        return;
    }
    if (self->first==self->second&&self->second==self->third){
        self->status = ROULETTE_33;
        if (strcmp("Unlock", block)==1){
            return;
        }
        for (i=0; i<self->size; i++){
            self->cb[i]("3 / 3", self->names[i], self);
        }
        return;
    }
    if (self->first==self->second||self->second==self->third||self->first==self->third){
        self->status = ROULETTE_23;
        if (strcmp("Unlock", block)==1){
            return;
        }
        for (i=0; i<self->size; i++){
            self->cb[i]("2 / 3", self->names[i], self);
        }
        return;
    }
    else {
        self->status = ROULETTE_03;
        if (strcmp("Unlock", block)==1){
            return;
        }
        for (i=0; i<self->size; i++){
            self->cb[i]("0 / 3", self->names[i], self);
        }
    }
    return;
}

roulette_status roulette_getstatus(roulette_t * self){
    return self->status;
}
