#include <SFML/Graphics.hpp>
#include "JackStandard.h"

class JackMessage{
public:
    bool isPressed(float x, float y);
    void win();
    void lose();
    void overflow();
    void draw();
    JackMessage();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
