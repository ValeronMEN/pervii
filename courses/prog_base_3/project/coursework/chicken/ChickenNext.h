#include <SFML/Graphics.hpp>
#include "ChickenStandard.h"

class ChickenNext{
public:
    bool isPressed(float x, float y);
    ChickenNext();
    sf::Sprite sprite;
    sf::Texture texture;
    void next();
    void win();
    void lose();

private:
    float posX;
    float posY;
    float width;
    float height;
};
