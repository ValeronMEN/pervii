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
    sf::Music music;
    sf::Texture background; //background texture
    sf::Sprite backgroundspr;

public:
    void start();
};
