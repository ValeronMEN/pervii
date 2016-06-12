#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "pig/PigStandard.h"
#include "pig/PigDeck.h"
#include "pig/PigBackCard.h"
#include "pig/PigTake.h"
#include "pig/PigCompare.h"
#include "pig/PigList.h"

class Pig{
private:
    sf::Texture background; //background texture
    sf::Sprite backgroundspr;
    sf::Texture backgroundGuide; //background texture
    sf::Sprite backgroundsprGuide;
    sf::Font myFont;
    sf::Text myScore;
    sf::Text coreScore;
    sf::Text aiScore;
    sf::Text middleScore;
    sf::Sprite tempSp;
    sf::Image image;
    void fonts();

public:
    void start();
    bool guide;
    int language;
};
