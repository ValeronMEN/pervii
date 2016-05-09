#include <SFML/Graphics.hpp>
#include "Card.h"
#include "ContinueButton.h"
#include "Standard.h"
#include "Deck.h"

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
