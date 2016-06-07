#ifndef PIGLIST_H
#define PIGLIST_H

#include "PigCard.h"

class PigList{
	private:
		PigCard card[40];
		int size;

	public:
	    PigList();

	    PigCard deleteIndex(int index);
	    void addIndex(int index, PigCard myCard);
        PigCard getIndex(int index);
        bool isEmpty();
        int getSize();
        void addLast(PigCard myCard);
        int getPoints();

};

#endif
