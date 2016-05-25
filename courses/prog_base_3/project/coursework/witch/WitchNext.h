#include <SFML/Graphics.hpp>

class WitchNext{
public:
    bool isPressed(float x, float y);
    WitchNext();
    sf::Sprite sprite;
    sf::Texture texture;
    void next();
    void take();
    void finish();

private:
    float posX;
    float posY;
    float width;
    float height;
};
