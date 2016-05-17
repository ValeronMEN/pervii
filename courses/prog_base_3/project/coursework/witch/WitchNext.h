#include <SFML/Graphics.hpp>

class WitchNext{
public:
    bool isPressed(float x, float y);
    WitchNext();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
