#include <SFML/Graphics.hpp>

class JackBet{
public:
    bool isPressed(float x, float y);
    JackBet();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
