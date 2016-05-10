#ifndef CARD_H
#define CARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class JackCard{
	private:
		short int colorIdentifier;
		std::string imagePath;

	public:
        short int valueIdentifier;
	    JackCard();

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
