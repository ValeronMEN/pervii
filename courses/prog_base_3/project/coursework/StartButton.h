#include <SFML/Graphics.hpp>

class StartButton{
public:
    bool isPressed(float x, float y);
    StartButton(int number);
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
