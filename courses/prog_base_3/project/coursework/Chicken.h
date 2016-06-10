#include "chicken/ChickenStandard.h"
#include "chicken/ChickenDeck.h"
#include "chicken/ChickenList.h"
#include "chicken/ChickenNext.h"
#include "chicken/ChickenBackCard.h"
#include <queue>
#include <string>

class Chicken{
private:
    sf::Font myFont;
    sf::Font aggFont;
    sf::Texture background; //background texture
    sf::Sprite backgroundspr;
    sf::Text wannaText;
    sf::Text strokeText;
    sf::Text mySize;
    sf::Text aiSize;
    sf::Image image;
    sf::Text myName;
    sf::Text aiName;
    void fonts(int strokeman);
    char * getWannaText(int);
    void getRound(int);

public:
    void start();
};
