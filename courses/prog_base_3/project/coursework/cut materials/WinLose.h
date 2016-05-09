#include <SFML/Graphics.hpp>

class WinLose{
public:
    bool isPressed(float x, float y);
    WinLose();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
