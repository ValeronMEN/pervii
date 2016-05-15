#include <SFML/Graphics.hpp>
#include "drunkard/Card.h"
#include "drunkard/ContinueButton.h"
#include "drunkard/DrunkardStandard.h"
#include "drunkard/Deck.h"
#include "drunkard/DrunkardReturn.h"

class Drunkard{
public:
    void start();

private:
    void drawDecks();
    sf::Texture backCardTex;
    sf::Sprite backCardSpr;
    sf::Sprite backCardSpr180;
    sf::Sprite backCardSpr2f;
    sf::Sprite backCardSpr2s;
};
