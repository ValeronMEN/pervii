#ifndef WITCHLIST_H
#define WITCHLIST_H

#include "WitchCard.h"

class WitchList{
	private:
		WitchCard card[36];
		int size;

	public:
	    WitchList();

	    WitchCard deleteIndex(int index);
	    void addIndex(int index, WitchCard myCard);
        WitchCard getIndex(int index);
        bool isEmpty();
        int getSize();
        void addLast(WitchCard myCard);

};

#endif // WITCHLIST_H
