#include <SFML/Graphics.hpp>

class JackMore{
public:
    bool isPressed(float x, float y);
    JackMore();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
