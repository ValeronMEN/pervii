#ifndef CARD_H
#define CARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class Card{
	private:
		short int valueIdentifier;
		short int colorIdentifier;
		std::string imagePath;

	public:
	    Card();

	    bool isClicked(int x, int y);
		short int getValueIdentifier();
		std::string getImagePath();
		short int getColorIdentifier();
		void setValueIdentifier(short int valueInput);
		void setImagePath(std::string pathInput);
		void setTexture();
		void setColorIdentifier(short int id);
		void drawOnScreen();

		int posX;
		int posY;
		int width;
		int height;
		bool visible;
		Sprite sprite;
		Texture texture;
};

#endif
