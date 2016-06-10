#include "ChickenDeck.h"

ChickenDeck::ChickenDeck(){
	this->pos = 0;

	int colorID = 0;
	int valueID = 0;

	for (int i = 0; i < 52; i++){
		this->card[i].setColorIdentifier(colorID);
		this->card[i].setValueIdentifier(valueID);
		this->card[i].setPoints((valueID+1));

		colorID++;

		if (colorID > 3){
			colorID = 0;
			valueID++;
		}
	}
}

ChickenCard ChickenDeck::getCard(){
	pos++;
	return card[pos-1];
}

void ChickenDeck::randomize()
{
    srand(std::time(0));
    this->pos = 0;
	ChickenCard cardSwipe;
	int id1, id2;
	for (int i = 0; i < 100; i++)
	{
		id1 = rand() % 52;
		id2 = rand() % 52;
		cardSwipe = this->card[id1];
		this->card[id1] = this->card[id2];
		this->card[id2] = cardSwipe;
	}
}

void ChickenDeck::randomizeNew()
{
    srand(std::time(0));
    this->pos = 0;
	ChickenCard cardSwipe;
	int id1, id2;
	for (int i = 0; i < 150; i++)
	{
		id1 = rand() % 36;
		id2 = rand() % 52;
		cardSwipe = this->card[id1];
		this->card[id1] = this->card[id2];
		this->card[id2] = cardSwipe;
	}
}
