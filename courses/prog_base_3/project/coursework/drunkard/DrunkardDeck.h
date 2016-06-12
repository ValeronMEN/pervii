#ifndef DRUNKARDDECK_H
#define DRUNKARDDECK_H

#include "DrunkardCard.h"

class DrunkardDeck{
	private:
		DrunkardCard card[36];
		int pos;

	public:
	    DrunkardDeck();
		DrunkardCard getCard();
		void randomize();
};

#endif
