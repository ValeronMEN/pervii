#include <SFML/Graphics.hpp>

class JackRate{
public:
    bool isPressed(float x, float y);
    JackRate();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
