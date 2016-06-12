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
    image.loadFromFile("textures/pigIco.png");
    window.setIcon(179, 179, image.getPixelsPtr());

    sf::RenderWindow windowGuide(sf::VideoMode(500, 700), "Guide", sf::Style::Titlebar);
    windowGuide.setVisible(false);

    if (guide==true)
    {
        window.setPosition(sf::Vector2i(30, 30));
        windowGuide.setVisible(true);

        windowGuide.setPosition(sf::Vector2i(1370, 170));
        if (language == 1){
            backgroundGuide.loadFromFile("textures/pigRules.png");
        }
        else{
            backgroundGuide.loadFromFile("textures/engPigRules.png");
        }
        backgroundsprGuide.setTexture(backgroundGuide);
        windowGuide.draw(backgroundsprGuide);
        windowGuide.display();
    }

    background.loadFromFile("textures/pigLoading.png");
    backgroundspr.setTexture(background);
    window.draw(backgroundspr);
    window.display();

    sf::Music music;
    if (!music.openFromFile("music/pyramid.ogg"))
    {
        return;
    }
    music.play();
    music.setLoop(true);

    //

    fonts();

    PigDeck * deck = new PigDeck();
    deck->randomize();

    PigTake * takeBtn = new PigTake();
    takeBtn->start();
    PigTake * message = new PigTake();
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
    bool middleVisible = false;
    int middlePoints = 0, checkPoints = 0; // a values to compare
    bool middleNew = true;
    bool middleFromCheck = false;

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
                    if (middleNew)
                    {
                        if (middleFromCheck)
                        {
                            *middleCard = *toCheck;
                            middleSize = middleList->getSize(); // set middle size
                            middleVisible = true; // show middle objects
                        }
                        else
                        {
                            middleList = new PigList();
                            if (deck->pos==MAGIC_NUMBER)
                            {
                                finish = true;
                                middleSize = 0; // set middle size
                                middleVisible = false; // show middle objects
                            }
                            else
                            {
                                *middleCard = deck->getCard(); /// to locate it in middle pre start
                                coreSize--; // one card must leave core deck
                                middleList->addLast(*middleCard); //add middle card to middle deck
                                middleSize = middleList->getSize(); // set middle size
                                middleVisible = true; // show middle objects
                            }

                            sprintf(text, AISCORE, aiSize, aiSum);
                            aiScore.setString(text);
                            sprintf(text, MYSCORE, mySize, mySum); // show player score
                            myScore.setString(text);
                        }
                        toCheckVisible = false;

                        sprintf(text, "%i", middleSize); // show sizes
                        middleScore.setString(text);
                        sprintf(text, CORESCORE, coreSize);
                        coreScore.setString(text);

                        middleCard->sprite.setPosition(20+139*2+32.5+250, 216+20+106); // set sprite of middle card
                        middleCard->setTexture();

                        if (strokeman == PLAYER)  // takeBtn skin
                        {
                            takeBtn->take();
                        }
                        else
                        {
                            takeBtn->watch();
                        }

                        middleNew = false;
                        break;
                    }
                    else // !middleNew
                    {
                        if (deck->pos==MAGIC_NUMBER)
                        {
                            finish = true;
                            toCheckVisible = false;
                            break;
                        }
                        toCheckVisible = true; // show objects of check

                        *toCheck = deck->getCard(); /// take card from core deck to check
                        coreSize--;
                        toCheck->setTexture();

                        sprintf(text, CORESCORE, coreSize); // show size of core deck
                        coreScore.setString(text);

                        checkPoints = toCheck->getPoints();
                        middlePoints = middleCard->getPoints();

                        middleList->addLast(*toCheck); // add toCheck card to list

                        if (strokeman == PLAYER)
                        {
                            toCheck->sprite.setPosition(20+139+32.5, 20+216+106); // special position in this case for toCheck!
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

                                middleNew = true;
                                middleFromCheck = true;
                                strokeman = AI;
                                takeBtn->finish();
                                break;
                            }
                            else  //(checkPoints > middlePoints)
                            {
                                compareToken->setPosition(20+139*2+32.5+25, 20+216+106+8, 0);

                                mySum = mySum + middleList->getPoints(); // special values that send to player (this time)
                                mySize = mySize + middleList->getSize();

                                strokeman = AI;
                                takeBtn->finish();
                                middleFromCheck = false;
                                middleNew = true;
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

                                middleNew = true;
                                middleFromCheck = true;
                                strokeman = PLAYER;
                                takeBtn->finish();
                                break;
                            }
                            else  //(checkPoints > middlePoints)
                            {
                                compareToken->setPosition(20+139*3+32.5+25+250, 20+216+106+8, 1);

                                aiSum = aiSum + middleList->getPoints();
                                aiSize = aiSize + middleList->getSize();

                                strokeman = PLAYER;
                                middleFromCheck = false;
                                middleNew = true;
                                takeBtn->finish();
                                break;
                            }
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
        if (middleVisible)
        {
            window.draw(middleScore);
            window.draw(middleCard->sprite);
        }
        window.draw(myScore);
        window.draw(aiScore);
        window.draw(coreScore);
        if (finish == true)
        {
            if (mySum > aiSum)
            {
                message->win();
            }
            else if (mySum < aiSum)
            {
                message->lose();
            }
            else
            {
                message->draw();
            }
            message->sprite.setPosition(20+139+32.5+139+25, 20+216+56);
            window.draw(message->sprite);
        }
        window.display();
    }
}
