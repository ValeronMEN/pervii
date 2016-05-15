#include <SFML/Graphics.hpp>

class JackPoints{
public:
    bool isPressed(float x, float y);
    JackPoints();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
