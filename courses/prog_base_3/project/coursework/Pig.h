#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "pig/PigStandard.h"
#include "pig/PigDeck.h"
#include "pig/PigBackCard.h"
#include "pig/PigTake.h"
#include "pig/PigCompare.h"
#include "pig/PigList.h"

#define MYSCORE "ME\nSIZE  %i\nSCORE  %i"
#define AISCORE "ENEMY!\nSIZE  %i\nSCORE  %i"
#define CORESCORE "SIZE  %i"
#define BUFFER 100

class Pig{
private:
    sf::Texture background; //background texture
    sf::Sprite backgroundspr;
    sf::Font myFont;
    sf::Text myScore;
    sf::Text coreScore;
    sf::Text aiScore;
    sf::Text middleScore;
    sf::Sprite tempSp;
    void fonts();

public:
    void start();
};
