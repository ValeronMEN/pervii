#include <SFML/Graphics.hpp>
#include "DrunkardStandard.h"

class ContinueButton{
public:
    bool isPressed(float x, float y);
    void win();
    void lose();
    ContinueButton();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
