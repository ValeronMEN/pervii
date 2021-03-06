#include "PigDeck.h"

PigDeck::PigDeck(){
	this->pos = 0;

	int colorID = 0;
	int valueID = 0;

	for (int i = 0; i < 40; i++){
		this->card[i].setColorIdentifier(colorID);
		this->card[i].setValueIdentifier(valueID);

		colorID++;

		if (colorID > 3){
			colorID = 0;
			valueID++;
		}
	}

	int points = 10;
	for (int i=0; i<40; i+=4){
        for (int j=0; j<4; j++){
            this->card[i+j].setPoints(points);
        }
        points--;
	}
}

PigCard PigDeck::getCard(){
	this->pos++;
	return card[pos-1];
}

void PigDeck::randomize()
{
    srand(std::time(0));
    this->pos = 0;
	PigCard cardSwipe;
	int id1, id2;
	for (int i = 0; i < 100; i++)
	{
		id1 = rand() % 40;
		id2 = rand() % 40;
		cardSwipe = this->card[id1];
		this->card[id1] = this->card[id2];
		this->card[id2] = cardSwipe;
	}
}

int PigDeck::getPoints(){
    int sum=0;
    for (int i=0; i<40; i++){
        sum = sum + card[i].getPoints();
    }
    return sum;
}
