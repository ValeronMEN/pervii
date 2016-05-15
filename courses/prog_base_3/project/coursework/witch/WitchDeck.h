#ifndef WITCHDECK_H
#define WITCHDECK_H

#include "WitchCard.h"

class WitchDeck{
	private:
		WitchCard card52[52];
		WitchCard card[52];
		int pos;

	public:
	    WitchDeck();
		WitchCard getCard();
		void randomize();
};

#endif
