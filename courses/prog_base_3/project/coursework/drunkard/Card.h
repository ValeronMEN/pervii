#ifndef CARD_H
#define CARD_H
#include <string>
#include <SFML/Graphics.hpp>

class Card{
	private:
		short int colorIdentifier;
		std::string imagePath;

	public:
        short int valueIdentifier;
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
		sf::Sprite sprite;
		sf::Texture texture;
};

#endif
