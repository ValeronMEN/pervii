#include <SFML/Graphics.hpp>

class JackOpen{
public:
    bool isPressed(float x, float y);
    void exit();
    JackOpen();
    sf::Sprite sprite;
    sf::Texture texture;

private:
    float posX;
    float posY;
    float width;
    float height;
};
