#include <stdio.h>
#include <stdlib.h>

#include "module.h"

int main()
{
    char text[MAX_TEXT_SIZE];

	FILE * file = fopen("mytext.txt", "r");
	fread(text, sizeof(char), MAX_TEXT_SIZE, file);

	text_t * myText = text_new(text);
	text_deleteStopWords(myText);

	text_free(myText);

	fclose(file);
	return 0;
}
