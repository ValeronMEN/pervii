#ifndef WITCHCARD_H
#define WITCHCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class WitchCard{
	private:
		short int colorIdentifier;
		short int valueIdentifier;
		int currwidth;
		int posX;
		int posY;
		int width;
		int height;

	public:
	    int points;
	    WitchCard();

	    bool isClicked(int x, int y);
	    bool isClickedCurr(int x, int y);
		short int getValueIdentifier();
		short int getColorIdentifier();
		void setValueIdentifier(short int valueInput);
		void setTexture();
		void setCutTexture();
		void setColorIdentifier(short int id);
		void setCurrTexture();
		void setCurrCutTexture();
		void setCoordinates(int x, int y);
		void drawOnScreen();
		void setPoints(int p);
		int getPoints();

		bool visible;
		Sprite sprite;
		Texture texture;
};

#endif