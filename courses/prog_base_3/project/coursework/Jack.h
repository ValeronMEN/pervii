#include <SFML/Graphics.hpp>
#include "jack/JackCard.h"
#include "jack/JackStandard.h"
#include "jack/JackDeck.h"
#include "jack/JackBet.h"
#include "jack/JackMoney.h"
#include "jack/JackRate.h"
#include "jack/JackLaunch.h"
#include "jack/JackMore.h"
#include "jack/JackOpen.h"
#include "jack/JackBackCard.h"
#include "jack/JackPoints.h"
#include "jack/JackMessage.h"

#define ERROR_CODE 2

class Jack{
private:
    sf::Image image;
    sf::Texture backgroundGuide;
    sf::Sprite backgroundsprGuide;

public:
    void start();
    int game(RenderWindow * win, int oneRate);
    bool guide;
    int language;
};
