#include <SFML/Graphics.hpp>
#include "DrunkardStandard.h"

class DrunkardReturn{
public:
    bool isPressed(float x, float y);
    DrunkardReturn();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
