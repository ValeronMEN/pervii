#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck{
	private:
		Card card[36];
		int pos;

	public:
	    Deck();
		Card getCard();
		void randomize();
};

#endif
