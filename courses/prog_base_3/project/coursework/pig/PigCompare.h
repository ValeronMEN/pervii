#include <SFML/Graphics.hpp>

class PigCompare{
public:
    bool isPressed(float x, float y);
    PigCompare();
    sf::Sprite sprite;
    sf::Texture texture;
    void setPosition(int x, int y, int compare);

private:
    float posX;
    float posY;
    float width;
    float height;
};
