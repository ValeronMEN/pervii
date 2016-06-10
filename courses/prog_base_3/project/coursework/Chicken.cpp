#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Chicken.h"

char * Chicken::getWannaText(int points)
{
    if (points==1)
    {
        return "ACE";
    }
    else if (points == 2)
    {
        return "SECUNDA";
    }
    else if (points == 3)
    {
        return "TERTIA";
    }
    else if (points == 4)
    {
        return "QUARTA";
    }
    else if (points == 5)
    {
        return "QUINTA";
    }
    else if (points == 6)
    {
        return "SEXTA";
    }
    else if (points == 7)
    {
        return "SEPTIMA";
    }
    else if (points == 8)
    {
        return "OCTAVA";
    }
    else if (points == 9)
    {
        return "NONA";
    }
    else if (points == 10)
    {
        return "DECIMA";
    }
    else if (points == 11)
    {
        return "JACK";
    }
    else if (points == 12)
    {
        return "QUEEN";
    }
    else if (points == 13)
    {
        return "KING";
    }
    else
    {
        return NULL;
    }
}

void Chicken::fonts(int strokeman)
{
    aggFont.loadFromFile("fonts/Agg.ttf");
    myFont.loadFromFile("fonts/shitan.otf");

    wannaText.setPosition(30+31+139+25+100, 30);
    wannaText.setColor(Color::Blue);
    wannaText.setFont(aggFont);
    wannaText.setCharacterSize(50);

    strokeText.setPosition(500-150 , C_Y - 100);
    strokeText.setColor(Color::Blue);
    strokeText.setFont(aggFont);
    strokeText.setCharacterSize(50);

    mySize.setPosition(30+139+5, 30+216/2-20);
    mySize.setColor(Color::White);
    mySize.setFont(myFont);
    mySize.setCharacterSize(30);

    aiSize.setPosition(C_X-139-30-25, C_Y-30-216/2-20);
    aiSize.setColor(Color::White);
    aiSize.setFont(myFont);
    aiSize.setCharacterSize(30);

    myName.setPosition(30+60, -2);
    myName.setColor(Color::White);
    myName.setFont(myFont);
    myName.setCharacterSize(30);

    aiName.setPosition(C_X-30-139/2-58, C_Y-35);
    aiName.setColor(Color::White);
    aiName.setFont(myFont);
    aiName.setCharacterSize(30);

    mySize.setString("52");
    aiSize.setString("52");
    wannaText.setString("I wanna see ACE!");
    if (strokeman == AI)
    {
        strokeText.setString("Enemy stroke...");
    }
    else
    {
        strokeText.setString("Your stroke...");
    }

    myName.setString("ME");
    aiName.setString("Guardian Devil");

    background.loadFromFile("textures/upGround1.png");
    backgroundspr.setTexture(background);
}

void Chicken::getRound(int round)
{
    if (round == 2)
    {
        wannaText.setColor(Color::Red);
        strokeText.setColor(Color::Red);
        background.loadFromFile("textures/upGround2.png");
        backgroundspr.setTexture(background);
    }
    else if(round == 3)
    {
        mySize.setColor(Color::Black);
        aiSize.setColor(Color::Black);
        background.loadFromFile("textures/upGround3.png");
        backgroundspr.setTexture(background);
        wannaText.setColor(sf::Color(115,0,0));
        strokeText.setColor(sf::Color(115,0,0));
        myName.setColor(Color::Black);
        aiName.setColor(Color::Black);
    }
    else if(round == 4)
    {
        mySize.setColor(Color::White);
        aiSize.setColor(Color::White);
        background.loadFromFile("textures/upGround4.png");
        backgroundspr.setTexture(background);
        wannaText.setColor(Color::White);
        strokeText.setColor(Color::White);
        myName.setColor(Color::White);
        aiName.setColor(Color::White);
    }
    else if(round == 5)
    {
        mySize.setColor(Color::Black);
        aiSize.setColor(Color::Black);
        background.loadFromFile("textures/upGround5.png");
        backgroundspr.setTexture(background);
        wannaText.setColor(Color::Black);
        strokeText.setColor(Color::Black);
        myName.setColor(Color::Black);
        aiName.setColor(Color::Black);
    }
    else if(round == 6)
    {
        mySize.setColor(Color::Red);
        aiSize.setColor(Color::Red);
        background.loadFromFile("textures/upGround6.png");
        backgroundspr.setTexture(background);
        wannaText.setColor(Color::Red);
        strokeText.setColor(Color::Red);
        myName.setColor(Color::Red);
        aiName.setColor(Color::Red);
    }
    else if(round == 7)
    {
        mySize.setColor(Color::White);
        aiSize.setColor(Color::White);
        background.loadFromFile("textures/upGround7.png");
        backgroundspr.setTexture(background);
        wannaText.setColor(Color::White);
        strokeText.setColor(Color::White);
        myName.setColor(Color::White);
        aiName.setColor(Color::White);
    }
    else
    {
        mySize.setColor(Color::White);
        aiSize.setColor(Color::White);
        background.loadFromFile("textures/upGround8.png");
        backgroundspr.setTexture(background);
        wannaText.setColor(Color::White);
        strokeText.setColor(Color::White);
        myName.setColor(Color::White);
        aiName.setColor(Color::White);
    }
}
void Chicken::start()
{
    sf::Music music;
    if (!music.openFromFile("music/outlaw.ogg"))
    {
        return; // error
    }
    music.play();
    music.setLoop(true);

    sf::RenderWindow window(sf::VideoMode(C_X, C_Y), "I WANNA", sf::Style::Close);
    image.loadFromFile("textures/upIco.png");
    window.setIcon(179, 179, image.getPixelsPtr());

    ChickenDeck * myDeck = new ChickenDeck();
    myDeck->randomize();
    ChickenDeck * aiDeck = new ChickenDeck();
    aiDeck->randomizeNew();
    ChickenCard * middleCard = new ChickenCard();
    ChickenCard * myCard = new ChickenCard();
    ChickenCard * aiCard = new ChickenCard();
    ChickenNext * nextBtn = new ChickenNext();
    nextBtn->next();
    ChickenNext * message = new ChickenNext();

    ChickenBackCard * myDeckSkin = new ChickenBackCard();
    ChickenBackCard * aiDeckSkin = new ChickenBackCard();
    aiDeckSkin->sprite.setPosition(30, 30);
    myDeckSkin->sprite.setPosition(C_X-30-139, C_Y-30-216);
    aiDeckSkin->setTexture();
    myDeckSkin->setTexture();

    std::queue<ChickenCard> myQueue;
    std::queue<ChickenCard> aiQueue;

    int strokeman = rand() % 2;
    fonts(strokeman);

    for (int i=0; i<52; i++)
    {
        myQueue.push(myDeck->getCard());
        aiQueue.push(aiDeck->getCard());
    }
    bool compareB = false;
    bool start = true;
    bool middleVisible = false;
    int myPoints = 0, aiPoints = 0, wannaPoints = 1;
    char text[C_BUFFER] = "";
    int round = 1;
    int myQueueSize, aiQueueSize;
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
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left))
            {
                if (nextBtn->isPressed(event.mouseButton.x, event.mouseButton.y) && (!finish))
                {
                    if (!start)
                    {
                        if (myPoints == wannaPoints && aiPoints == wannaPoints)
                        {
                            if (strokeman == PLAYER)
                            {
                                *middleCard = *myCard;
                                myQueue.pop();
                                aiQueue.push(aiQueue.front());
                                aiQueue.pop();
                                wannaPoints++;
                            }
                            else
                            {
                                *middleCard = *aiCard;
                                aiQueue.pop();
                                myQueue.push(myQueue.front());
                                myQueue.pop();
                                wannaPoints++;
                            }
                            middleVisible = true;
                        }
                        else if(myPoints == wannaPoints)
                        {
                            *middleCard = *myCard;
                            myQueue.pop();
                            aiQueue.push(aiQueue.front());
                            aiQueue.pop();
                            wannaPoints++;
                            middleVisible = true;
                        }
                        else if (aiPoints == wannaPoints)
                        {
                            *middleCard = *aiCard;
                            aiQueue.pop();
                            myQueue.push(myQueue.front());
                            myQueue.pop();
                            wannaPoints++;
                            middleVisible = true;
                        }
                        else
                        {
                            myQueue.push(myQueue.front());
                            myQueue.pop();
                            aiQueue.push(aiQueue.front());
                            aiQueue.pop();
                        }
                        if (middleVisible)
                        {
                            middleCard->setTexture();
                            middleCard->sprite.setPosition(430.5, C_Y-550);
                        }
                        if (wannaPoints==14)
                        {
                            round++;
                            wannaPoints = 1;
                            getRound(round);
                        }
                        sprintf(text, WANNACONST, getWannaText(wannaPoints));
                        wannaText.setString(text);
                        myQueueSize = myQueue.size();
                        sprintf(text, "%i", myQueueSize);
                        mySize.setString(text);
                        aiQueueSize = aiQueue.size();
                        sprintf(text, "%i", aiQueueSize);
                        aiSize.setString(text);
                        if (myQueueSize == 0 || aiQueueSize == 0)
                        {
                            finish = true;
                            if (myQueueSize == 0){
                                message->win();
                            }
                            else{
                                message->lose();
                            }
                            break;
                        }
                    }
                    compareB = true;
                    start = false;
                    *myCard = myQueue.front();
                    *aiCard = aiQueue.front();
                    myCard->setTexture();
                    aiCard->setTexture();
                    myCard->sprite.setPosition(30, 30+216+30);
                    aiCard->sprite.setPosition(C_X-139-30, C_Y-30-216-216-30);
                    myPoints = myCard->getPoints();
                    aiPoints = aiCard->getPoints();
                    if (strokeman == PLAYER)
                    {
                        strokeman = AI;
                        strokeText.setString("Enemy stroke...");
                    }
                    else
                    {
                        strokeman = PLAYER;
                        strokeText.setString("Your stroke...");
                    }
                }
            }
        }
        window.clear(sf::Color(0,115,0));
        if (finish == true)
        {
            window.draw(message->sprite);
        }
        else
        {
            window.draw(backgroundspr);
            window.draw(myDeckSkin->sprite);
            window.draw(aiDeckSkin->sprite);
            if (compareB == true)
            {
                window.draw(myCard->sprite);
                window.draw(aiCard->sprite);
            }
            if (middleVisible)
            {
                window.draw(middleCard->sprite);
            }
            window.draw(nextBtn->sprite);
            window.draw(mySize);
            window.draw(aiSize);
            window.draw(wannaText);
            window.draw(strokeText);
            window.draw(myName);
            window.draw(aiName);
        }
        window.display();
    }
    return;
}
