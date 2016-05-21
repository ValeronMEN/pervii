#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"

char* user(events ev, const char * name){
    printf("%s, you have 0 / 3\n", name);
    if (ev==NOTUSING){
        printf("%s: Book will be mine!\n", name);
        return name;
    }
    return NULL;
}

struct library_s{
    int size;
    book_t * arr[MAX_LIBRARY_SIZE];
    library_status status;
};

book_t * book_new(char * author, char * title, int size){
    book_t * myBook = malloc(sizeof(struct book_s));
    myBook->title = malloc(MAX_NAME_SIZE * sizeof(char));
    myBook->author = malloc(MAX_NAME_SIZE * sizeof(char));
    strcpy(myBook->title, title);
    strcpy(myBook->author, author);
    myBook->size = size;
    return myBook;
}

book_t * book_new_prototype(){
    book_t * myBook = malloc(sizeof(struct book_s));
    myBook->title = malloc(MAX_NAME_SIZE * sizeof(char));
    myBook->author = malloc(MAX_NAME_SIZE * sizeof(char));
    myBook->size = 0;
    return myBook;
}

void book_free(book_t * myBook){
    free(myBook->title);
    free(myBook->author);
    free(myBook);
}

void book_print(book_t * myBook){
    printf("Title: %s; Author: %s; Size: %i;", myBook->title, myBook->author, myBook->size);
}

library_t * library_new(){
    library_t * myLibrary = malloc(sizeof(struct library_s));
    myLibrary->size = 0;
    myLibrary->status = LIBRARY_OK;
    return myLibrary;
}

void library_free(library_t * myLibrary){
    int i;
    for(i=0; i<myLibrary->size; i++){
        book_free(myLibrary->arr[i]);
    }
    free(myLibrary->arr);
    free(myLibrary);
}

void library_addIndex(library_t * myLibrary, book_t * book, int index){
    myLibrary->status = LIBRARY_OK;
    if (myLibrary->size==MAX_LIBRARY_SIZE){
        myLibrary->status = LIBRARY_OVERFLOW;
        return;
    }
    if ((index > myLibrary->size) || (index < 0)){
        index=myLibrary->size;
    }
    int i;
    for(i=myLibrary->size; i>index; i--){
        myLibrary->arr[i] = myLibrary->arr[i-1];
    }
    myLibrary->arr[index] = book;
    myLibrary->size++;
}

book_t * library_subIndex(library_t * myLibrary, int index){
    myLibrary->status = LIBRARY_OK;
    if (myLibrary->size == 0){
        myLibrary->status = LIBRARY_UNDERFLOW;
        return NULL;
    }
    if ((index >= myLibrary->size) || (index < 0)){
        myLibrary->status = LIBRARY_BADINDEX;
        return NULL;
    }
    book_t * book = book_new_prototype();
    book = myLibrary->arr[index];
    int i;
    for(i=index; i<myLibrary->size; i++){
        myLibrary->arr[i] = myLibrary->arr[i+1];
    }
    myLibrary->size--;
    return book;
}

library_status library_getStatus(library_t * myLibrary){
    return myLibrary->status;
}

int library_getCount(library_t * myLibrary){
    return myLibrary->size;
}

void library_view(library_t * myLibrary){
    int i;
    for(i=0; i<myLibrary->size; i++){
        book_print(myLibrary->arr[i]);
        puts("");
    }
}

void book_subs(book_t * myBook, MyCallback excb){
    if (myBook->subs_size==MAX_SUBSCRIBERS_SIZE){
        printf("Subscribers overflow!\n");
        myBook->status = BOOK_SUBSCRIBERS_OVERFLOW;
        return;
    }
    myBook->cb[myBook->subs_size] = excb;
    //strcpy(myBook->names[myBook->subs_size], name);
    myBook->subs_size++;
}

void books_isUsing(library_t * mylib){
    int i;
    for(i=0; i<mylib->size; i++){
        if (mylib->arr[i]->user!=NULL){
            book_print(mylib->arr[i]);
        }
    }
}


