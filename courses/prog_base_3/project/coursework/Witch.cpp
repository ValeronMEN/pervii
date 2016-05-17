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
    WitchList * myList = new WitchList();
    WitchList * aiList = new WitchList();
    WitchCard card[36];
    WitchCard tempCard;
    WitchBackCard * backcard[36];
    WitchBackCard * retreat = new WitchBackCard();
    for (int i=0; i<36; i++)
    {
        backcard[i] = new WitchBackCard();
    }
    int strokeman = rand() % 2; //0 - player, 1 - ai
    bool throwOpportunity = false;
    if (strokeman==PLAYER){
        throwOpportunity = true;
    }
    WitchThrow * throwBtn = new WitchThrow();
    WitchNext * nextBtn = new WitchNext();


    //set texture of retreat
    retreat->setTexture();
    retreat->sprite.setPosition(W_X-149 , 308+42);

    // card distribution to player and ai
    int i=0;
    while(i<18)
    {
        myList->addIndex(-1, deck->getCard());
        aiList->addIndex(-1, deck->getCard());
        i++;
    }

    // set textures of lists of player and ai
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
                    if (toChoose==0) // only one card to get from ai
                    {
                        for(int i=0; i<(aiList->getSize()-1); i++)
                        {
                            if ((backcard[i]->isClickedCurr(event.mouseButton.x, event.mouseButton.y))&&(backcard[i]->getHighlighted() == false))
                            {
                                backcard[i]->setCurrCutTexture();
                                backcard[i]->setHighlighted(true);
                                toChoose++;
                                break;
                            }
                        }
                        if ((backcard[aiList->getSize()-1]->isClicked(event.mouseButton.x, event.mouseButton.y))&&(backcard[aiList->getSize()-1]->getHighlighted() == false))
                        {
                            backcard[aiList->getSize()-1]->setCurrTexture();
                            backcard[aiList->getSize()-1]->setHighlighted(true);
                            toChoose++;
                            break;
                        }
                    }
                    if ((twoHighlighted<2)&&(throwOpportunity==true)) //only 2 cards to throw
                    {
                        for(int i=0; i<(myList->getSize()-1); i++)
                        {
                            if ((card[i].isClickedCurr(event.mouseButton.x, event.mouseButton.y))&&(card[i].getHighlighted() == false))
                            {
                                card[i].setCurrCutTexture();
                                card[i].setHighlighted(true);
                                twoHighlighted++;
                                break;
                            }
                        }

                        if ((card[myList->getSize()-1].isClicked(event.mouseButton.x, event.mouseButton.y))&&(card[myList->getSize()-1].getHighlighted() == false))
                        {
                            card[myList->getSize()-1].setCurrTexture();
                            card[myList->getSize()-1].setHighlighted(true);
                            twoHighlighted++;
                            break;
                        }
                    }

                    if ((throwBtn->isPressed(event.mouseButton.x, event.mouseButton.y))&&(twoHighlighted == 2)&&(throwOpportunity==true))
                    {
                        for(int i=0; i<myList->getSize(); i++)
                        {
                            for (int j=0; j<myList->getSize(); j++)
                            {
                                if ((card[i].getHighlighted()==true)&&(card[j].getHighlighted()==true)&&(i!=j)&&(card[i].getValueIdentifier()!=card[j].getValueIdentifier()))
                                {
                                    throwOpportunity = false;
                                }
                            }
                        }
                        if (throwOpportunity == false){
                            throwOpportunity = true;
                            break;
                        }

                        player_x=10;

                        for(i=0; i<=myList->getSize(); i++)
                        {
                            if (card[i].getHighlighted()==true)
                            {
                                if (twoHighlighted==1)
                                {
                                    myList->deleteIndex(i-1);
                                    twoHighlighted--;
                                }
                                if (twoHighlighted==2)
                                {
                                    myList->deleteIndex(i);
                                    twoHighlighted--;
                                }
                            }
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
                        throwOpportunity = false;
                        break;
                    }

                }
                if((event.mouseButton.button == sf::Mouse::Right))
                {
                    if (toChoose==1) // only one card to get from ai
                    {
                        for(int i=0; i<(aiList->getSize()-1); i++)
                        {
                            if ((backcard[i]->isClickedCurr(event.mouseButton.x, event.mouseButton.y))&&(backcard[i]->getHighlighted() == true))
                            {
                                backcard[i]->setTexture();
                                backcard[i]->setHighlighted(false);
                                toChoose--;
                                break;
                            }
                        }
                        if ((backcard[aiList->getSize()-1]->isClicked(event.mouseButton.x, event.mouseButton.y))&&(backcard[aiList->getSize()-1]->getHighlighted() == true))
                        {
                            backcard[aiList->getSize()-1]->setTexture();
                            backcard[aiList->getSize()-1]->setHighlighted(false);
                            toChoose--;
                            break;
                        }
                    }

                    if ((twoHighlighted>0)) //only 2 cards to throw
                    {
                        for(int i=0; i<(myList->getSize()-1); i++)
                        {
                            if ((card[i].isClickedCurr(event.mouseButton.x, event.mouseButton.y))&&(card[i].getHighlighted() == true))
                            {
                                card[i].setCutTexture();
                                card[i].setHighlighted(false);
                                twoHighlighted--;
                                break;
                            }
                        }

                        if ((card[myList->getSize()-1].isClicked(event.mouseButton.x, event.mouseButton.y))&&(card[myList->getSize()-1].getHighlighted() == true))
                        {
                            card[myList->getSize()-1].setTexture();
                            card[myList->getSize()-1].setHighlighted(false);
                            twoHighlighted--;
                            break;
                        }
                    } // twoHighlighted
                } // Right button of mouse

            } // mouse button pressed
        } // second loop
        window.clear(sf::Color(0,115,0));
        for (int i=0; i<myList->getSize(); i++)
        {
            window.draw(card[i].sprite);
        }
        for (int i=0; i<aiList->getSize(); i++)
        {
            window.draw(backcard[i]->sprite);
        }
        if ((myList->getSize() + aiList->getSize()) != 36)
        {
            window.draw(retreat->sprite);
        }
        if ((twoHighlighted==2)&&(throwOpportunity==true))
        {
            window.draw(throwBtn->sprite);
        }
        window.draw(nextBtn->sprite);
        window.display();
    } // first loop
}
