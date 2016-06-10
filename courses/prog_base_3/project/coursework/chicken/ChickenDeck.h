#ifndef CHICKENDECK_H
#define CHICKENDECK_H

#include "ChickenCard.h"

class ChickenDeck{
	private:
		ChickenCard card[52];
		int pos;

	public:
	    ChickenDeck();
		ChickenCard getCard();
		void randomize();
		void randomizeNew();
};

#endif
