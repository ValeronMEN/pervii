#ifndef PIGCARD_H
#define PIGCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class PigCard{
	private:
		short int colorIdentifier;
		short int valueIdentifier;
		int currwidth;
		int posX;
		int posY;
		int width;
		int height;
		bool highlighted;
		bool queenofspades;

	public:
	    int points;
	    PigCard();

	    bool isClicked(int x, int y);
	    bool isClickedCurr(int x, int y);
	    void setHighlighted(bool b);
		short int getValueIdentifier();
		short int getColorIdentifier();
		void setValueIdentifier(short int valueInput);
		void setTexture();
		void setCutTexture();
		void setColorIdentifier(short int id);
		void setCurrTexture();
		void setCurrCutTexture();
		void setCoordinates(int x, int y);
		void setPoints(int p);
		int getPoints();
		bool getHighlighted();
		bool getQueenOfSpades();
		void setQueenOfSpades();

		Sprite sprite;
		Texture texture;
};

#endif
