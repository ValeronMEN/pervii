#include <SFML/Graphics.hpp>

class JackLaunch{
public:
    bool isPressed(float x, float y);
    JackLaunch();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
