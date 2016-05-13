#include <SFML/Graphics.hpp>
#include "jack/JackCard.h"
#include "Standard.h"
#include "jack/JackDeck.h"
#include "jack/JackBet.h"
#include "jack/JackMoney.h"
#include "jack/JackRate.h"
#include "jack/JackLaunch.h"
#include "jack/JackMore.h"
#include "jack/JackOpen.h"
#include "jack/JackBackCard.h"

class Jack{
public:
    void start();
    void game(RenderWindow * win, int bank, int oneRate);
};
