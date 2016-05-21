#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#define MAX_LIBRARY_SIZE 20
#define MAX_NAME_SIZE 100
#define MAX_SUBSCRIBERS_SIZE 10
#define MAX_TAKERS_SIZE 10

typedef enum events{USING=0, NOTUSING=1} events;
typedef char* (*MyCallback)(events, const char *);

typedef enum book_status{
    BOOK_SUBSCRIBERS_OVERFLOW,
    BOOK_USING,
    BOOK_NOTUSING,
    BOOK_PROTOTYPE,
} book_status;

typedef struct library_s library_t;
typedef struct book_s book_t;
typedef struct user_s user_t;

typedef enum library_status{
    LIBRARY_OK,
    LIBRARY_OVERFLOW,
    LIBRARY_UNDERFLOW,
    LIBRARY_BADINDEX,
} library_status;

book_t * book_new(char * author, char * title, int size);
void book_free(book_t * myBook);
void book_print(book_t * myBook);

char* user(events ev, const char * name);
void book_subs(book_t * myBook, char* (*excb)(events, const char *));

void book_taking(book_t * myBook, user_t * user);
void book_puting(book_t * myBook, user_t * user);

library_t * library_new();
void library_free(library_t * myLibrary);

void library_addIndex(library_t * myLibrary, book_t * book, int index);
book_t * library_subIndex(library_t * myLibrary, int index);
library_status library_getStatus(library_t * myLibrary);
int library_getCount(library_t * myLibrary);
void library_view(library_t * myLibrary);

void books_isUsing(library_t * mylib);
void books_isNotUsing(library_t * mylib);

#endif // LIBRARY_H_INCLUDED
