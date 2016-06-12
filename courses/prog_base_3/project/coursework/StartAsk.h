#include <SFML/Graphics.hpp>

class StartAsk{
public:
    bool isPressed(float x, float y);
    StartAsk(int, int);
    sf::Sprite sprite;
    sf::Texture texture;
    void english();
    void ukrainian();
    void guide();
    void guideAbs();

private:
    float posX;
    float posY;
    float width;
    float height;
};
