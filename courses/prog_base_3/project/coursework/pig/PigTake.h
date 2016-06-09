#include <SFML/Graphics.hpp>

class PigTake{
public:
    bool isPressed(float x, float y);
    PigTake();
    sf::Sprite sprite;
    sf::Texture texture;

    void take();
    void start();
    void watch();

private:
    float posX;
    float posY;
    float width;
    float height;
};
