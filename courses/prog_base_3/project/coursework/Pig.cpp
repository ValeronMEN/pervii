#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pig.h"

void Pig::fonts()
{
    Color * color = new Color(0, 0, 0, 255);
    myFont.loadFromFile("fonts/Antropofagia.ttf");

    myScore.setPosition(20+139+10 , P_Y-20-216+50);
    myScore.setColor(*color);
    myScore.setFont(myFont);
    myScore.setCharacterSize(50);

    middleScore.setPosition(20+32.5+139*2+250+50 , 20+216+106-70);
    middleScore.setColor(Color::White);
    middleScore.setFont(myFont);
    middleScore.setCharacterSize(55);

    coreScore.setPosition(20+139+10 , 20);
    coreScore.setColor(*color);
    coreScore.setFont(myFont);
    coreScore.setCharacterSize(50);

    aiScore.setPosition(P_X-139-20-216-110 , 20);
    aiScore.setColor(*color);
    aiScore.setFont(myFont);
    aiScore.setCharacterSize(50);

    coreScore.setString("SIZE  40");
    middleScore.setString("0");
    myScore.setString("ME\nSIZE  0\nSCORE  0");
    aiScore.setString("ENEMY!\nSIZE  0\nSCORE  0");

    background.loadFromFile("textures/pigPyramid.png");
    backgroundspr.setTexture(background);
}

void Pig::start()
{
    sf::RenderWindow window(sf::VideoMode(P_X, P_Y), "Pig");

    sf::Music music;
    if (!music.openFromFile("music/pyramid.ogg"))
    {
        return;
    }
    music.play();

    fonts();

    PigDeck * deck = new PigDeck();
    deck->randomize();

    PigTake * takeBtn = new PigTake();
    PigCompare * compareToken = new PigCompare();
    PigCard * toCheck = new PigCard();
    PigCard * middleCard = new PigCard();
    PigList * middleList = new PigList();
    int mySize=0, aiSize=0, coreSize = 40, middleSize = 0; //my and AI scores

    PigBackCard * aiDeck = new PigBackCard(false); // textures of decks
    PigBackCard * myDeck = new PigBackCard(false);
    PigBackCard * coreDeck = new PigBackCard(true);
    aiDeck->sprite.setPosition(1300-139-20, 20);
    myDeck->sprite.setPosition(20, 900-20-216);
    coreDeck->sprite.setPosition(20, 20);

    int strokeman = rand() % 2;
    bool toCheckVisible = false;
    bool finish = false;
    int mySum = 0, aiSum = 0; // for sum in middle list
    char text[BUFFER];
    bool start = true;
    bool middleVisible = false;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)&&(!finish))
            {
                if (takeBtn->isPressed(event.mouseButton.x, event.mouseButton.y))
                {
                    if (start)
                    {
                        *middleCard = deck->getCard();
                        coreSize--;
                        middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
                        middleCard->setTexture();
                        middleList->addLast(*middleCard);
                        middleSize = middleList->getSize();
                        sprintf(text, "%i", middleSize);
                        middleScore.setString(text);
                        sprintf(text, CORESCORE, coreSize);
                        coreScore.setString(text);
                        middleVisible = true;
                        start = false;
                        break;
                    }
                    if (deck->pos==40)
                    {
                        toCheckVisible = false;
                        finish = true;
                        break;
                    }
                    toCheckVisible = true;
                    middleCard->setTexture();
                    *toCheck = deck->getCard();
                    coreSize--;
                    middleSize = middleList->getSize();
                    sprintf(text, "%i", middleSize);
                    middleScore.setString(text);
                    toCheck->setTexture();
                    if (strokeman == PLAYER)
                    {
                        toCheck->sprite.setPosition(20+139+32.5, 20+216+106);
                        if (toCheck->getPoints()>=middleCard->getPoints())
                        {
                            if (toCheck->getPoints() == middleCard->getPoints())
                            {
                                compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 2);
                            }
                            else
                            {
                                compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 0);
                            }
                            middleList->addLast(*toCheck);///
                            tempSp = middleCard->sprite;
                            *middleCard = *toCheck;
                            middleCard->sprite = tempSp;
                            middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
                            sprintf(text, CORESCORE, coreSize);
                            coreScore.setString(text);
                            strokeman = AI;
                            break;
                        }
                        else if (toCheck->getPoints()<middleCard->getPoints())
                        {
                            compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 1);
                            middleList->addLast(*middleCard);///
                            mySum += middleList->getPoints();
                            mySize += middleList->getSize();
                            sprintf(text, MYSCORE, mySize, mySum);
                            myScore.setString(text);
                            middleList = new PigList();
                            if (deck->pos!=40)
                            {
                                middleList->addLast(*toCheck);///
                                tempSp = middleCard->sprite;
                                //*middleCard = deck->getCard();

                                middleSize = middleList->getSize();
                                sprintf(text, "%i", middleSize);
                                middleScore.setString(text);
                                coreSize--;
                                *middleCard = *toCheck;
                                middleCard->sprite = tempSp;
                                middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
                            }
                            else{
                                middleVisible = false;
                            }
                            sprintf(text, CORESCORE, coreSize);
                            coreScore.setString(text);
                            strokeman = AI;
                            break;
                        }
                    }
                    else
                    {
                        toCheck->sprite.setPosition(20+139*3+32.5+250*2, 20+216+106);
                        if (toCheck->getPoints()>=middleCard->getPoints())
                        {
                            if (toCheck->getPoints() == middleCard->getPoints())
                            {
                                compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 2);
                            }
                            else
                            {
                                compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 1);
                            }
                            middleList->addLast(*toCheck);///
                            tempSp = middleCard->sprite;
                            *middleCard = *toCheck;
                            middleCard->sprite = tempSp;
                            middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
                            sprintf(text, CORESCORE, coreSize);
                            coreScore.setString(text);
                            strokeman = PLAYER;
                            break;
                        }
                        else if (toCheck->getPoints()<middleCard->getPoints())
                        {
                            compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 0);
                            middleList->addLast(*middleCard);///
                            aiSum += middleList->getPoints();
                            aiSize += middleList->getSize();
                            sprintf(text, AISCORE, aiSize, aiSum);
                            aiScore.setString(text);
                            middleList = new PigList();
                            if (deck->pos!=40)
                            {
                                middleList->addLast(*toCheck);///
                                tempSp = middleCard->sprite;
                                //*middleCard = deck->getCard();
                                middleSize = middleList->getSize();
                                sprintf(text, "%i", middleSize);
                                middleScore.setString(text);
                                coreSize--;
                                *middleCard = *toCheck;
                                middleCard->sprite = tempSp;
                                middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);
                            }
                            else{
                                middleVisible = false;
                            }
                            sprintf(text, CORESCORE, coreSize);
                            coreScore.setString(text);
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
        if (toCheckVisible)
        {
            window.draw(toCheck->sprite);
            window.draw(compareToken->sprite);
        }
        if (middleVisible){
            window.draw(middleScore);
            window.draw(middleCard->sprite);
        }
        window.draw(myScore);
        window.draw(aiScore);
        window.draw(coreScore);
        window.display();
    }
}
