#include <SFML/Graphics.hpp>
#include "witch/WitchStandard.h"
#include "witch/WitchDeck.h"
#include "witch/WitchList.h"
#include "witch/WitchBackCard.h"
#include "witch/WitchNext.h"
#include "witch/WitchThrow.h"
#include "witch/WitchMessage.h"
#include "witch/WitchResult.h"
#include "witch/WitchStroke.h"

class Witch{
private:
    sf::Texture background;
    sf::Sprite backgroundspr;
    sf::Image image;
    sf::Texture backgroundGuide;
    sf::Sprite backgroundsprGuide;

public:
    void start();
    bool guide;
    int language;
};
