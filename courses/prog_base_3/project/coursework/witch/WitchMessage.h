#include <SFML/Graphics.hpp>

class WitchMessage{
public:
    bool isPressed(float x, float y);
    WitchMessage();
    sf::Sprite sprite;
    sf::Texture texture;
    void selectcard();

private:
    float posX;
    float posY;
    float width;
    float height;
};
