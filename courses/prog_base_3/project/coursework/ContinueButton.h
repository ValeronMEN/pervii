#include <SFML/Graphics.hpp>
#include "Standard.h"

class ContinueButton{
public:
    bool isPressed(float x, float y);
    ContinueButton();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
