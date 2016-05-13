#ifndef DECK_H
#define DECK_H

#include "JackCard.h"

class JackDeck{
	private:
		JackCard card[52];
		int pos;

	public:
	    JackDeck();
		JackCard getCard();
		void randomize();
};

#endif
