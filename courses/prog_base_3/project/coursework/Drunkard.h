#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <queue>
#include <windows.h>

#include "drunkard/DrunkardCard.h"
#include "drunkard/DrunkardContinueButton.h"
#include "drunkard/DrunkardStandard.h"
#include "drunkard/DrunkardDeck.h"
#include "drunkard/DrunkardReturn.h"

class Drunkard{
public:
    void start();
    bool guide;
    int language;

private:
    void drawDecks();
    sf::Texture backCardTex;
    sf::Sprite backCardSpr;
    sf::Sprite backCardSpr180;
    sf::Sprite backCardSpr2f;
    sf::Sprite backCardSpr2s;
    sf::Texture background;
    sf::Sprite backgroundspr;
    sf::Image image;
    sf::Font myFont;
    sf::Text strokeText;
    sf::Texture backgroundGuide;
    sf::Sprite backgroundsprGuide;
};
