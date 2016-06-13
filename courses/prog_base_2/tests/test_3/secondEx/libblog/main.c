#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "blog.h"

struct comment_s{
    int id;

    char author[MAX_NAME_SIZE];
    char text[MAX_TEXT_SIZE];
};

struct post_s{
    int id;

    char text[MAX_TEXT_SIZE];

    comment_t * comments[MAX_COMMENTS_SIZE];
    int comments_size;
};

struct user_s{
    int id;

    char name[MAX_NAME_SIZE];
    char surname[MAX_NAME_SIZE];
    char country[MAX_NAME_SIZE];
    int years;
    char login[MAX_NAME_SIZE];
    user_status status;

    post_t * posts[MAX_POSTS_SIZE];
    int posts_size;
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
    for (i=0; i<myNetwork->size; i++){
        user_free(myNetwork, myNetwork->users[i]);
    }
    free(myNetwork);
}

user_t * user_new(int id, char * login, char * name, char * surname, int years, char * country, valerooncom_t * myNetwork){
    myNetwork->status = OK;
    if (myNetwork->size == MAX_USERS_SIZE){
        myNetwork->status = OVERFLOW;
        return NULL;
    }

    user_t * myUser = malloc(sizeof(struct user_s));
    myUser->status = USER_OK;
    myUser->id = id;
    myUser->years = years;
    myUser->posts_size = 0;
    strcpy(myUser->name, name);
    strcpy(myUser->surname, surname);
    strcpy(myUser->country, country);
    strcpy(myUser->login, login);

    myNetwork->users[myNetwork->size] = myUser;
    myNetwork->size++;

    return myUser;
}

user_t * user_get(valerooncom_t * myNetwork, int id){
    myNetwork->status = OK;
    int i;
    for (i=0; i<myNetwork->size; i++){
        if (myNetwork->users[i]->id == id){
            return myNetwork->users[i];
        }
    }
    return NULL;
}

void user_edit(int id, valerooncom_t * myNetwork, char * login, char * name, char * surname, int years, char * country){
    myNetwork->status = OK;
    user_t * myUser = user_get(myNetwork, id);
    if (myUser == NULL){
        myNetwork->status = ID_ABS;
        return;
    }
    strcpy(myUser->name, name);
    strcpy(myUser->surname, surname);
    strcpy(myUser->country, country);
    strcpy(myUser->login, login);
    myUser->id = id;
    myUser->years = years;
    return;
}

comment_t * comment_new(user_t * userThatPost, post_t * myPost, char * text){
    if (strcmp(text, "")==0){
        return NULL;
    }
    if (myPost->comments_size == MAX_COMMENTS_SIZE){
        return NULL;
    }
    comment_t * myComment = malloc(sizeof(struct comment_s));
    strcpy(myComment->author, userThatPost->name);
    strcpy(myComment->text, text);
    myPost->comments[myPost->comments_size] = myComment;
    myPost->comments_size++;
    return myComment;
}

void comment_free(comment_t * myComment, post_t * myPost){
    myPost->comments_size--;

    free(myComment);
}

post_t * post_new(char * text, user_t * myUser){
    if (strcmp(text, "")==0){
        return NULL;
    }
    if (myUser->posts_size == MAX_POSTS_SIZE){
        return NULL;
    }
    post_t * myPost = malloc(sizeof(struct post_s));
    strcpy(myPost->text, text);
    myUser->posts[myUser->posts_size] = myPost;
    myUser->posts_size++;
    return myPost;
}

void post_free(user_t * myUser, post_t * myPost){
    myUser->posts_size--;
    free(myPost);
}

void user_free(valerooncom_t * myNetwork, user_t * myUser){
    myNetwork->size--;
    int i;
    for(i=0; i<myUser->posts_size; i++){
        post_free(myUser, myUser->posts[i]);
    }
    free(myUser);
}

void user_view(user_t * myUser){
    printf("Id: %i\nLogin: %s\nName: %s\nSurname: %s\nCountry: %s\nYears: %i\nPosts size: %i\n\n",
           myUser->id, myUser->login, myUser->name, myUser->surname, myUser->country, myUser->years, myUser->posts_size);
    if (myUser->posts_size!=0){
        int i;
        for (i=0; i<myUser->posts_size; i++){
            post_print(myUser->posts[i]);
        }
    }
    else{
        printf("There is no posts yet\n\n");
    }
}

void post_print(post_t * myPost){
    printf("%s", myPost->text);
}
