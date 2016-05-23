#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "module.h"

struct text_s{
    char * text;
    list_t * listOfSentences;
};

struct sentence_s{
    char * sentence;
    list_t * listOfWords;
};

struct word_s{
    char * word;
};

struct stopwords_s{
    list_t * stopwords;
};

word_t * word_new(char * value){
    word_t * myWord = malloc(sizeof(struct word_s));
	myWord->word = malloc((strlen(value)+1)*sizeof(char));
	strcpy(myWord->word, value);
	//puts(myWord->word);
	return myWord;
}

sentence_t * sentence_new(char * value){
    sentence_t * mySentence = malloc(sizeof(struct sentence_s));
	mySentence->sentence = malloc((strlen(value)+1)*sizeof(char));
	strcpy(mySentence->sentence, value);
	mySentence->listOfWords = list_new();
	//puts(value);

	char * p;
    char del[] = ", ?!;:&";
    p = strtok(mySentence->sentence, del);
    int j=0, i;
    char * p_copy[1000];
    while(p != NULL){
        p_copy[j] = p;
        p = strtok(NULL, del);
        j++;
    }
    for (i=0; i<j; i++){
        //puts(p_copy[i]);
        list_push_back(mySentence->listOfWords, word_new(p_copy[i]));
    }

	return mySentence;
}

text_t * text_new(char * value){
    text_t * myText = malloc(sizeof(struct text_s));
	myText->text = malloc((strlen(value)+1)*sizeof(char));
	strcpy(myText->text, value);
	myText->listOfSentences = list_new();

	char * p;
    char del[] = ".";
    p = strtok(myText->text, del);
    int j=0, i;
    char * p_copy[1000];
    while(p != NULL){
        p_copy[j] = p;
        p = strtok(NULL, del);
        j++;
    }
    for (i=0; i<j; i++){
        //puts(p_copy[i]);
        list_push_back(myText->listOfSentences, sentence_new(p_copy[i]));
    }

	return myText;
}

stopwords_t * stopwords_new(){
    stopwords_t * myStopwords = malloc(sizeof(struct stopwords_s));
    myStopwords->stopwords = list_new();

    char text[MAX_TEXT_SIZE];
	FILE * file = fopen("stopwords.txt", "r");
	fread(text, sizeof(char), MAX_TEXT_SIZE, file);

	char * p;
    char del[] = "\n";
    p = strtok(text, del);
    int j=0, i;
    char * p_copy[1000];
    while(p != NULL){
        p_copy[j] = p;
        p = strtok(NULL, del);
        j++;
    }
    for (i=0; i<j; i++){
        //puts(p_copy[i]);
        list_push_back(myStopwords->stopwords, word_new(p_copy[i]));
    }

    fclose(file);
	return myStopwords;
}

void sentence_deleteStopWord(sentence_t * mySentence, stopwords_t * myStopwords, FILE * file){
    int i, j, truth;
    for (i=0; i<list_getSize(mySentence->listOfWords); i++){
        truth=1;
        word_t * myWord = list_remove(mySentence->listOfWords, i);
        for (j=0; j<list_getSize(myStopwords->stopwords); j++){
            word_t * myStopword = list_get(myStopwords->stopwords, j);
            if(strcmp(myWord->word, myStopword->word)==0){
                puts(myWord->word);
                puts(myStopword->word);
                truth=0;
                i++;
                break;
            }
        }
        if (truth==1){
            list_insert(mySentence->listOfWords, i, myWord);
            fwrite(myWord->word, sizeof(char), (strlen(myWord->word)), file);
            fwrite(", ", sizeof(char), 2, file);
        }
    }
}

void text_deleteStopWords(text_t * myText){
    FILE * file = fopen("result.txt", "w");

    int i;
    stopwords_t * myStopwords = stopwords_new();
    for (i=0; i<list_getSize(myText->listOfSentences); i++){
        sentence_t * mySentence = list_remove(myText->listOfSentences, i);
        sentence_deleteStopWord(mySentence, myStopwords, file);
        list_insert(myText->listOfSentences, i, mySentence);
        fwrite("\n", sizeof(char), 2, file);
    }

    fclose(file);
}

void word_free(word_t * myWord){
    free(myWord);
}

void sentence_free(sentence_t * mySentence){
    int i;
    for(i=0; i<list_getSize(mySentence->listOfWords); i++){
        word_free(list_get(mySentence->listOfWords, i));
    }
    list_free(mySentence->listOfWords);
    free(mySentence);
}

void text_free(text_t * myText){
    int i;
    for(i=0; i<list_getSize(myText->listOfSentences); i++){
        sentence_free(list_get(myText->listOfSentences, i));
    }
    list_free(myText->listOfSentences);
    free(myText);
}


