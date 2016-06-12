#include <SFML/Graphics.hpp>
#include "DrunkardStandard.h"

class DrunkardContinueButton{
public:
    bool isPressed(float x, float y);
    void win();
    void lose();
    DrunkardContinueButton();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
