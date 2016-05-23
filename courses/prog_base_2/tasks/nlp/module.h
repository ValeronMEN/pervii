#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED

#define MAX_TEXT_SIZE 20000
#define MAX_SENTENCE_SIZE 500
#define MAX_WORD_SIZE 30

#include "list.h"

typedef struct text_s text_t;
typedef struct sentence_s sentence_t;
typedef struct word_s word_t;
typedef struct stopwords_s stopwords_t;

text_t * text_new(char * value);
void text_deleteStopWords(text_t * myText);
void text_free(text_t * myText);

#endif // MODULE_H_INCLUDED
