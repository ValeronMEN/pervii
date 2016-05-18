#include <SFML/Graphics.hpp>

class WitchResult{
public:
    bool isPressed(float x, float y);
    WitchResult();
    sf::Sprite sprite;
    sf::Texture texture;
    void win();
    void lose();

private:
    float posX;
    float posY;
    float width;
    float height;
};
