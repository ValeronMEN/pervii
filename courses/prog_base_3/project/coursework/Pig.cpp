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
    sf::RenderWindow window(sf::VideoMode(P_X, P_Y), "Sons of Pharaoh", sf::Style::Close);

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
    takeBtn->start();
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
    int middlePoints = 0, checkPoints = 0; // a values to compare

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
                        *middleCard = deck->getCard(); // to locate it in middle pre start
                        coreSize--; // one card must leave core deck
                        middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106); // set sprite of middle card
                        middleCard->setTexture();

                        middleList->addLast(*middleCard); //add middle card to middle deck

                        middleSize = middleList->getSize(); // set middle size
                        sprintf(text, "%i", middleSize); // show sizes
                        middleScore.setString(text);
                        sprintf(text, CORESCORE, coreSize);
                        coreScore.setString(text);

                        if (strokeman == PLAYER){ // takeBtn skin
                            takeBtn->take();
                        }
                        else{
                            takeBtn->watch();
                        }
                        middleVisible = true; // show middle objects
                        start = false; // finish start point way
                        break;
                    }
                    if (deck->pos==MAGIC_NUMBER) // check to empty core deck
                    {
                        toCheckVisible = false; // hide objects of check
                        finish = true; // start finish point way
                        break;
                    }

                    toCheckVisible = true; // show objects of check

                    //middleCard->setTexture();

                    *toCheck = deck->getCard(); // take card from core deck to check
                    coreSize--;
                    toCheck->setTexture();

                    sprintf(text, CORESCORE, coreSize); // show size of core deck
                    coreScore.setString(text);

                    checkPoints = toCheck->getPoints();
                    middlePoints = middleCard->getPoints();

                    middleList->addLast(*toCheck); // add toCheck card to list

                    if (strokeman == PLAYER)
                    {
                        toCheck->sprite.setPosition(20+139+32.5, 20+216+106); // special position in this case
                        if (checkPoints <= middlePoints)
                        {
                            if (checkPoints == middlePoints)
                            {
                                compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 2); // '=' token
                            }
                            else
                            {
                                compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 1);
                            }

                            tempSp = middleCard->sprite;
                            *middleCard = *toCheck;
                            middleCard->sprite = tempSp;

                            middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);

                            middleSize = middleList->getSize(); // set & show middle size
                            sprintf(text, "%i", middleSize);
                            middleScore.setString(text);

                            strokeman = AI;
                            takeBtn->watch();
                            break;
                        }
                        else{ //(checkPoints > middlePoints)
                            compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 0);

                            middleList->addLast(*middleCard);// add middle card to middle deck to take it

                            mySum += middleList->getPoints(); // special values that send to player (this time)
                            mySize += middleList->getSize();

                            sprintf(text, MYSCORE, mySize, mySum); // show player score
                            myScore.setString(text);

                            middleList = new PigList(); // do it empty

                            if (deck->pos != MAGIC_NUMBER)
                            {
                                *middleCard = deck->getCard(); // take new card from core deck
                                coreSize--;

                                sprintf(text, "%i", middleSize=1); // show middle size
                                middleScore.setString(text);

                                middleCard->setTexture();
                                middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);

                                sprintf(text, CORESCORE, coreSize); // show core size
                                coreScore.setString(text);
                            }
                            else{
                                middleVisible = false; // to finish
                            }

                            strokeman = AI;
                            takeBtn->watch();
                            break;
                        }
                    }
                    else
                    {
                        toCheck->sprite.setPosition(20+139*3+32.5+250*2, 20+216+106);
                        if (checkPoints <= middlePoints)
                        {
                            if (checkPoints == middlePoints)
                            {
                                compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 2);
                            }
                            else
                            {
                                compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 0);
                            }

                            tempSp = middleCard->sprite;
                            *middleCard = *toCheck;
                            middleCard->sprite = tempSp;

                            middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);

                            middleSize = middleList->getSize(); // set & show middle size
                            sprintf(text, "%i", middleSize);
                            middleScore.setString(text);

                            strokeman = PLAYER;
                            takeBtn->take();
                            break;
                        }
                        else{ //(checkPoints > middlePoints)
                            compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 1);

                            middleList->addLast(*middleCard);// add middle card to middle deck to take it

                            aiSum += middleList->getPoints();
                            aiSize += middleList->getSize();

                            sprintf(text, AISCORE, aiSize, aiSum);
                            aiScore.setString(text);

                            middleList = new PigList();

                            if (deck->pos != MAGIC_NUMBER)
                            {
                                *middleCard = deck->getCard(); // take new card from core deck
                                coreSize--;

                                sprintf(text, "%i", middleSize=1); // show middle size
                                middleScore.setString(text);

                                middleCard->setTexture();
                                middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106);

                                sprintf(text, CORESCORE, coreSize); // show core size
                                coreScore.setString(text);
                            }
                            else{
                                middleVisible = false;
                            }

                            strokeman = PLAYER;
                            takeBtn->take();
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
