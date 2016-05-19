#include <SFML/Graphics.hpp>
#include "WitchStandard.h"

class WitchStroke{
public:
    bool isPressed(float x, float y);
    WitchStroke();
    sf::Sprite sprite;
    sf::Texture texture;
    void mystroke();
    void aistroke();

private:
    float posX;
    float posY;
    float width;
    float height;
};
