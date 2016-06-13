#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "blog.h"

struct user_s{
    int id;
    char name[MAX_NAME_SIZE];
    char surname[MAX_NAME_SIZE];
    char country[MAX_NAME_SIZE];
    int years;
    char login[MAX_NAME_SIZE];
    user_status status;
};

struct valerooncom_s{
    user_t * users[MAX_USERS_SIZE];
    int size;
    valerooncom_status status;
};

valerooncom_t * valerooncom_new(){
    valerooncom_t * myNetwork = malloc(sizeof(struct valerooncom_s));
    myNetwork->size = 0;
    myNetwork->status = OK;
    return myNetwork;
}

void valerooncom_free(valerooncom_t * myNetwork){
    int i;
    //for (i=0; i<myNetwork->size; i++){
    //    myNetwork->users[i] = user_free();
    //}
    free(myNetwork);
}

user_t * user_new(int id, char * login, char * name, char * surname, int years, char * country){
    user_t * myUser = malloc(sizeof(struct valerooncom_s));
    myUser->status = OK;
    myUser->id = id;
    myUser->years = years;
    strcpy(myUser->name, name);
    strcpy(myUser->surname, surname);
    strcpy(myUser->country, country);
    strcpy(myUser->login, login);
    return myUser;
}
