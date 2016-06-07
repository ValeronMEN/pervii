#ifndef PIGCARD_H
#define PIGCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class PigCard{
	private:
		short int colorIdentifier;
		short int valueIdentifier;
		int posX;
		int posY;
		int width;
		int height;

	public:
	    int points;
	    PigCard();

	    bool isClicked(int x, int y);
		short int getValueIdentifier();
		short int getColorIdentifier();
		void setValueIdentifier(short int valueInput);
		void setTexture();
		void setColorIdentifier(short int id);
		void setCoordinates(int x, int y);
		void setPoints(int p);
		int getPoints();

		Sprite sprite;
		Texture texture;
};

#endif
