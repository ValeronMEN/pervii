#include "DrunkardDeck.h"

DrunkardDeck::DrunkardDeck(){
	this->pos = 0;

	int colorID = 0;
	int valueID = 0;

	for (int  i = 0; i < 36; i++)
	{
		this->card[i].setColorIdentifier(colorID);
		this->card[i].setValueIdentifier(valueID);

		colorID++;

		if (colorID > 3)
		{
			colorID = 0;
			valueID++;
		}
	}
}

DrunkardCard DrunkardDeck::getCard(){
	pos++;
	return card[pos-1];
}

void DrunkardDeck::randomize()
{
    srand(std::time(0));
    this->pos = 0;
	DrunkardCard cardSwipe;
	int id1, id2;
	for (int i = 0; i < 100; i++)
	{
		id1 = rand() % 36;
		id2 = rand() % 36;
		cardSwipe = this->card[id1];
		this->card[id1] = this->card[id2];
		this->card[id2] = cardSwipe;
	}
}
