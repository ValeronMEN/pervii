#ifndef PIGBACKCARD_H
#define PIGBACKCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class PigBackCard{
	private:
		int currwidth;
		int posX;
		int posY;
		int width;
		int height;
		bool highlighted;

	public:
	    int points;
	    PigBackCard();

	    void setHighlighted(bool b);

	    bool isClicked(int x, int y);
	    bool isClickedCurr(int x, int y);
		void setTexture();
		void setCutTexture();
		void setCurrTexture();
		void setCurrCutTexture();
		void setCoordinates(int x, int y);
		bool getHighlighted();

		Sprite sprite;
		Texture texture;
};

#endif
