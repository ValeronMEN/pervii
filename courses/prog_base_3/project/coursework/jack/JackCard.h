#ifndef CARD_H
#define CARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class JackCard{
	private:
		short int colorIdentifier;
		short int valueIdentifier;

	public:
	    int points;
	    JackCard();

	    bool isClicked(int x, int y);
		short int getValueIdentifier();
		short int getColorIdentifier();
		void setValueIdentifier(short int valueInput);
		void setTexture();
		void setColorIdentifier(short int id);
		void drawOnScreen();
		void setPoints(int p);
		int getPoints();

		int posX;
		int posY;
		int width;
		int height;
		bool visible;
		Sprite sprite;
		Texture texture;
};

#endif
