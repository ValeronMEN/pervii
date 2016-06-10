#ifndef CHICKENLIST_H
#define CHICKENLIST_H

#include "ChickenCard.h"

class ChickenList{
	private:
		ChickenCard card[36];
		int size;

	public:
	    ChickenList();

	    ChickenCard deleteIndex(int index);
	    void addIndex(int index, ChickenCard myCard);
        ChickenCard getIndex(int index);
        bool isEmpty();
        int getSize();
        void addLast(ChickenCard myCard);

};

#endif
