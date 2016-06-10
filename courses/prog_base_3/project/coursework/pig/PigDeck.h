#ifndef PIGDECK_H
#define PIGDECK_H

#include "PigCard.h"

class PigDeck{
	private:
		PigCard card[40];

	public:
	    int pos;
	    PigDeck();
		PigCard getCard();
		bool isEmpty();
		void randomize();
		int getPoints();
};

#endif
