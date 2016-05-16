#include <SFML/Graphics.hpp>
#include "Witch.h"
#include <windows.h>

using namespace sf;

void Witch::start()
{
    sf::RenderWindow window(sf::VideoMode(W_X, W_Y), "Witch");
    window.clear(sf::Color(0,115,0));
    window.display();
    WitchDeck * deck = new WitchDeck();
    deck->randomize();

    int player_x = 10;
    int casino_x = W_X-(139+10);
    short int twoHighlighted = 0;
    short int toChoose = 0;
    WitchCard * selectedHL[2];
    WitchCard * selectedC;

    WitchList * myList = new WitchList();
    WitchList * aiList = new WitchList();
    WitchList * firstList = myList;
    WitchList * secondList = aiList;

    WitchCard card[36];
    WitchBackCard * backcard[36];
    WitchBackCard * retreat = new WitchBackCard();

    retreat->setTexture();
    retreat->sprite.setPosition(W_X-149 , 308+42);

    for (int i=0; i<36; i++)
    {
        backcard[i] = new WitchBackCard();
    }

    int strokeman = rand() % 2;
    if (strokeman == 1)
    {
        firstList = aiList;
        secondList = myList;
    }
    int i=0;
    while(i<18)
    {
        myList->addIndex(-1, deck->getCard());
        aiList->addIndex(-1, deck->getCard());
        i++;
    }

    for (int i=0; i<myList->getSize(); i++)
    {
        card[i] = myList->getIndex(i);
        card[i].sprite.setPosition(player_x, W_Y-10-216);
        card[i].setCoordinates(player_x, W_Y-10-216);
        if((myList->getSize()-1)==i)
        {
            card[i].setTexture();
        }
        else
        {
            card[i].setCutTexture();
        }
        player_x += 23;
    }

    for (int i=0; i<aiList->getSize(); i++)
    {
        backcard[i]->sprite.setPosition(casino_x, 10);
        backcard[i]->setCoordinates(casino_x, 10);
        backcard[i]->setTexture();
        casino_x -= 23;
    }

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if((event.mouseButton.button == sf::Mouse::Left))
                {
                    if (toChoose<1) // only one card to get from ai
                    {
                        for(int i=0; i<(aiList->getSize()-1); i++)
                        {
                            if (backcard[i]->isClickedCurr(event.mouseButton.x, event.mouseButton.y))
                            {
                                backcard[i]->setCurrCutTexture();
                                toChoose++;
                            }
                        }
                        if (backcard[aiList->getSize()-1]->isClicked(event.mouseButton.x, event.mouseButton.y))
                        {
                            backcard[aiList->getSize()-1]->setCurrTexture();
                            toChoose++;
                        }
                    }
                    if ((twoHighlighted<2)) //only 2 cards to throw
                    {
                        for(int i=0; i<(myList->getSize()-1); i++)
                        {
                            if (card[i].isClickedCurr(event.mouseButton.x, event.mouseButton.y))
                            {
                                card[i].setCurrCutTexture();
                                twoHighlighted++;
                            }
                        }

                        if (card[myList->getSize()-1].isClicked(event.mouseButton.x, event.mouseButton.y))
                        {
                            card[myList->getSize()-1].setCurrTexture();
                            twoHighlighted++;
                        }
                    }

                }
            }
        }
        window.clear(sf::Color(0,115,0));
        for (int i=0; i<myList->getSize(); i++)
        {
            window.draw(card[i].sprite);
            window.draw(backcard[i]->sprite);
        }
        if ((myList->getSize() + aiList->getSize()) != 36){
            window.draw(retreat->sprite);
        }
        window.display();
    }
}
