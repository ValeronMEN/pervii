#ifndef CHICKENBACKCARD_H
#define CHICKENBACKCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class ChickenBackCard{
	private:
		int posX;
		int posY;
		int width;
		int height;

	public:
	    ChickenBackCard();

	    bool isClicked(int x, int y);
		void setTexture();
		void setCoordinates(int x, int y);

		Sprite sprite;
		Texture texture;
};

#endif
