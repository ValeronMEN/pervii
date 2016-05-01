#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roulette.h"

struct roulette_s{
    int first;
    int second;
    int third;
    MyCallback cb[MAX_SUBSCRIBERS_SIZE];
    char names[MAX_NAME_SIZE][MAX_SUBSCRIBERS_SIZE];
    int size;
};

roulette_t * roulette_new(){
    roulette_t * self = malloc(sizeof(struct roulette_s));
    self->first = 0;
    self->second = 0;
    self->third = 0;
    self->size = 0;
    return self;
}

void roulette_free(roulette_t * self){
    free(self);
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

void player(const char * message, const char * name){
    printf("%s, you have %s\n", name, message);
    if (strcmp(message, "0 / 3")==0){
        printf("I'm sorry, but you're not a winner :(\n");
        return;
    }
    if (strcmp(message, "2 / 3")==0){
        printf("You're not a winner, but close to victory! :)\n");
        return;
    }
    if (strcmp(message, "3 / 3")==0){
        printf("You're a winner! :D\n");
        return;
    }
    if (strcmp(message, "Jackpot!")==0){
        printf("You're a super winner! :D\n");
        return;
    }
}

void administrator(const char * message, const char * name){
    if (strcmp(message, "Jackpot!")==0){
        printf("Administrator %s informed. He will come soon\n", name);
        return;
    }
    else {
        return;
    }
}

void press(const char * message, const char * name){
    if (strcmp(message, "Jackpot!")==0){
        printf("Press '%s' informed. They will come soon\n", name);
        return;
    }
    else {
        return;
    }
}

void roulette_subs(roulette_t * self, MyCallback excb, const char * name){
    if (self->size==MAX_SUBSCRIBERS_SIZE){
        printf("Subscribers overflow!\n");
        return;
    }
    self->cb[self->size] = excb;
    strcpy(self->names[self->size], name);
    self->size++;
}

void roulette_randomizer(roulette_t * self, int a, int b, int c){ //f function
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
        for (i=0; i<self->size; i++){
            self->cb[i]("Jackpot!", self->names[i]);
        }
        return;
    }
    if (self->first==self->second&&self->second==self->third){
        for (i=0; i<self->size; i++){
            self->cb[i]("3 / 3", self->names[i]);
        }
        return;
    }
    if (self->first==self->second||self->second==self->third||self->first==self->third){
        for (i=0; i<self->size; i++){
            self->cb[i]("2 / 3", self->names[i]);
        }
        return;
    }
    else {
        for (i=0; i<self->size; i++){
            self->cb[i]("0 / 3", self->names[i]);
        }
    }
    return;
}
