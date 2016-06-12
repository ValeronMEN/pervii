#ifndef DRUNKARDCARD_H
#define DRUNKARDCARD_H
#include <string>
#include <SFML/Graphics.hpp>

class DrunkardCard{
	private:
		short int colorIdentifier;
		int posX;
		int posY;
		int width;
		int height;

	public:
        short int valueIdentifier;
	    DrunkardCard();

	    bool isClicked(int x, int y);
		short int getValueIdentifier();
		short int getColorIdentifier();
		void setValueIdentifier(short int valueInput);
		void setTexture();
		void setColorIdentifier(short int id);
		void drawOnScreen();

		bool visible;
		sf::Sprite sprite;
		sf::Texture texture;
};

#endif
