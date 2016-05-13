#ifndef JACKBACKCARD_H
#define JACKBACKCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class JackBackCard{

	public:
	    JackBackCard();

	    bool isClicked(int x, int y);

		int posX;
		int posY;
		int width;
		int height;
		bool visible;
		Sprite sprite;
		Texture texture;
};

#endif
