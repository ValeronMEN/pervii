#include "WitchDeck.h"

WitchDeck::WitchDeck(){
	this->pos = 0;

	int colorID = 0;
	int valueID = 0;

	for (int i = 0; i < 52; i++){
		this->card52[i].setColorIdentifier(colorID);
		this->card52[i].setValueIdentifier(valueID);

		colorID++;

		if (colorID > 3){
			colorID = 0;
			valueID++;
		}
	}

	for(int i=0; i<4; i++){
        this->card[i] = this->card52[i];
	}

	for(int i=4; i<36; i++){
        this->card[i] = this->card52[(i+16)];
	}

}

WitchCard WitchDeck::getCard(){
	pos++;
	return card[pos-1];
}

void WitchDeck::randomize()
{
    srand(std::time(0));
    this->pos = 0;
	WitchCard cardSwipe;
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
