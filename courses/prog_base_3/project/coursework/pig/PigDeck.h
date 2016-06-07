#ifndef PIGDECK_H
#define PIGDECK_H

#include "PigCard.h"

class PigDeck{
	private:
		PigCard card[40];
		int pos;

	public:
	    PigDeck();
		PigCard getCard();
		void randomize();
};

#endif
