#include <SFML/Graphics.hpp>

class WitchThrow{
public:
    bool isPressed(float x, float y);
    WitchThrow();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
