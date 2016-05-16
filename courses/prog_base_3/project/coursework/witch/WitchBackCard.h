#ifndef WITCHBACKCARD_H
#define WITCHBACKCARD_H
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

class WitchBackCard{
	private:
		int currwidth;
		int posX;
		int posY;
		int width;
		int height;
		bool highlighted;

	public:
	    int points;
	    WitchBackCard();

	    void setHighlighted(bool b);

	    bool isClicked(int x, int y);
	    bool isClickedCurr(int x, int y);
		void setTexture();
		void setCutTexture();
		void setCurrTexture();
		void setCurrCutTexture();
		void setCoordinates(int x, int y);

		Sprite sprite;
		Texture texture;
};

#endif
