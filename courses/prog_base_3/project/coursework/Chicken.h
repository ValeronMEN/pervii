#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <queue>
#include <string>

#include "chicken/ChickenStandard.h"
#include "chicken/ChickenDeck.h"
#include "chicken/ChickenList.h"
#include "chicken/ChickenNext.h"
#include "chicken/ChickenBackCard.h"

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
    void getRound(int);

public:
    void start();
};
