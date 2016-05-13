#include <SFML/Graphics.hpp>

class JackMoney{
public:
    bool isPressed(float x, float y);
    JackMoney();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
