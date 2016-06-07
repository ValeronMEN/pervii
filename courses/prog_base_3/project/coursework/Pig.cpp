#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pig.h"

void Pig::start()
{
    sf::RenderWindow window(sf::VideoMode(P_X, P_Y), "Pig");

    if (!music.openFromFile("music/pyramid.ogg"))
    {
        return;
    }
    //music.play();

    background.loadFromFile("textures/pigPyramid.png");
    backgroundspr.setTexture(background);

    PigDeck * deck = new PigDeck();
    deck->randomize();

    PigTake * takeBtn = new PigTake();
    PigCompare * compareToken = new PigCompare();
    PigCard * toCheck = new PigCard();
    PigCard * middleCard = new PigCard();
    *middleCard = deck->getCard();
    middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
    middleCard->setTexture();
    PigList * middleList = new PigList();
    int mySize=0, aiSize=0; //my and AI scores

    PigBackCard * aiDeck = new PigBackCard(); // textures of decks
    PigBackCard * myDeck = new PigBackCard();
    PigBackCard * coreDeck = new PigBackCard();
    aiDeck->sprite.setPosition(1300-139-20, 20);
    myDeck->sprite.setPosition(20, 900-20-216);
    coreDeck->sprite.setPosition(20, 20);

    int strokeman = rand() % 2;
    bool toCheckVisible = false;
    bool finish = false;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)&&(!finish)){
                if (takeBtn->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    if (deck->pos==40){
                        toCheckVisible = false;
                        finish = true;
                        break;
                    }
                    *toCheck = deck->getCard();
                    toCheck->setTexture();
                    toCheckVisible = true;
                    if (strokeman == PLAYER){
                        toCheck->sprite.setPosition(20+139+32.5, 20+216+106);
                        if (toCheck->getPoints()>middleCard->getPoints()){
                            compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 0);
                            middleList->addLast(*toCheck);
                            *middleCard = *toCheck;
                            middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
                            middleCard->setTexture();
                            strokeman = AI;
                            break;
                        }
                        else if (toCheck->getPoints()<middleCard->getPoints()){
                            compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 1);

                            strokeman = AI;
                            break;
                        }
                        else{
                            compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 2);
                            strokeman = AI;
                            break;
                        }
                    }
                    else{
                        toCheck->sprite.setPosition(20+139*3+32.5+250*2, 20+216+106);
                        if (toCheck->getPoints()>middleCard->getPoints()){
                            compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 1);
                            // add toCheck to list
                            //*middleCard = *toCheck;
                            strokeman = PLAYER;
                            break;
                        }
                        else if (toCheck->getPoints()<middleCard->getPoints()){
                            compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 0);
                            strokeman = PLAYER;
                            break;
                        }
                        else{
                            compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 2);
                            strokeman = PLAYER;
                            break;
                        }
                    }
                }
            }
        }
        window.clear(sf::Color(0,115,0));
        window.draw(backgroundspr);
        window.draw(aiDeck->sprite);
        window.draw(myDeck->sprite);
        window.draw(coreDeck->sprite);
        window.draw(takeBtn->sprite);
        if (toCheckVisible){
            window.draw(toCheck->sprite);
            window.draw(compareToken->sprite);
        }
        window.draw(middleCard->sprite);
        window.display();
    }
}
