#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Witch.h"

using namespace sf;

void Witch::start()
{
    sf::Music music;
    if (!music.openFromFile("music/vf.ogg"))
    {
        return; // error
    }
    music.play();
    music.setLoop(true);

    background.loadFromFile("textures/witchcity.png");
    backgroundspr.setTexture(background);

    sf::RenderWindow window(sf::VideoMode(W_X, W_Y), "Palmfever", sf::Style::Close);
    image.loadFromFile("textures/witchIco.png");
    window.setIcon(179, 179, image.getPixelsPtr());

    sf::RenderWindow windowGuide(sf::VideoMode(500, 700), "Guide", sf::Style::Titlebar);
    windowGuide.setVisible(false);

    if (guide==true)
    {
        window.setPosition(sf::Vector2i(100, 30));
        windowGuide.setVisible(true);

        windowGuide.setPosition(sf::Vector2i(1370, 170));
        if (language == 1){
            backgroundGuide.loadFromFile("textures/witchRules.png");
        }
        else{
            backgroundGuide.loadFromFile("textures/engWitchRules.png");
        }
        backgroundsprGuide.setTexture(backgroundGuide);
        windowGuide.draw(backgroundsprGuide);
        windowGuide.display();
    }

    WitchResult * resultBtn = new WitchResult(); //loading window
    window.clear(sf::Color(0,115,0));
    window.draw(resultBtn->sprite);
    window.display();

    WitchDeck * deck = new WitchDeck(); // core deck
    deck->randomize();// to random the deck
    int player_x = 10; //pos x for my cards
    int casino_x = W_X-(139+10); // pos x for ai cards
    short int twoHighlighted = 0;//for opportunity  to block choosing more than 2 cards
    short int toChoose = 0; //for opportunity to choose cards from ai
    WitchList * myList = new WitchList(); // list of my cards
    WitchList * aiList = new WitchList(); // list of ai cards
    WitchCard card[36]; // an array of my cards
    WitchCard tempCard;
    WitchBackCard * backcard[36]; //textures of ai cards
    WitchBackCard * retreat = new WitchBackCard(); // retreat texture
    for (int i=0; i<36; i++)
    {
        backcard[i] = new WitchBackCard();
    }
    int strokeman = rand() % 2; //0 - player, 1 - ai
    bool messageIncluded = false;// to include upper small message about bad status of game
    bool throwOpportunity = false; //for opportunity to throw cards to retreat
    bool finish = false; //to finish game; to block whole buttons
    bool playerTakeOpportunity = false; //for opportunity to take a card from ai
    bool aiTakeOpportunity = false;
    if (strokeman==PLAYER)
    {
        throwOpportunity = true;
    }
    WitchThrow * throwBtn = new WitchThrow(); // throw button
    WitchNext * nextBtn = new WitchNext(); // next button
    WitchMessage * message = new WitchMessage(); // upper message block
    WitchStroke * strokeBtn = new WitchStroke();

    if (strokeman==PLAYER)
    {
        strokeBtn->mystroke();
        nextBtn->take();
        playerTakeOpportunity = true;
    }
    else
    {
        strokeBtn->aistroke();
        nextBtn->next();
    }

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
                if((event.mouseButton.button == sf::Mouse::Left)&&(finish==false))
                {
                    if ((toChoose==0)&&(strokeman==PLAYER)&&(playerTakeOpportunity==true)) // only one card to get from ai
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
                    if ((twoHighlighted<2)&&(throwOpportunity==true)&&(strokeman==PLAYER)) //only 2 cards to throw
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
                        messageIncluded = false;
                        // check to truth of throwing cards
                        for(int i=0; i<myList->getSize(); i++)
                        {
                            for (int j=0; j<myList->getSize(); j++)
                            {
                                if ((card[i].getHighlighted()==true)&&(card[j].getHighlighted()==true)&&(i!=j))
                                {
                                    if ((card[i].getQueenOfSpades()==true)||(card[j].getQueenOfSpades()==true))
                                    {
                                        message->witch();
                                        messageIncluded = true;
                                        goto toexit;
                                    }
                                    if (card[i].getValueIdentifier()!=card[j].getValueIdentifier())
                                    {
                                        message->selecttwoidentical();
                                        messageIncluded = true;
                                        goto toexit;
                                    }
                                    goto tostart;
                                }
                            }
                        }

                        // start of throwing
tostart:
                        player_x=10;
                        for(int i=0; i<=myList->getSize(); i++)
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
                        //end of throwing
                        throwOpportunity = false;
                        break;
                    }
                    if (nextBtn->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        if (strokeman == PLAYER)
                        {
                            if (playerTakeOpportunity==true)
                            {
                                messageIncluded = true;
                                for(int i=0; i<=aiList->getSize(); i++)
                                {
                                    if (backcard[i]->getHighlighted()==true)
                                    {
                                        messageIncluded = false;
                                        toChoose = 0;
                                        backcard[i]->setHighlighted(false);
                                        myList->addLast(aiList->deleteIndex(i));

                                        for(int j=0; j<myList->getSize(); j++)
                                        {
                                            card[j].setHighlighted(false);
                                        }
                                        twoHighlighted = 0;

                                        player_x = 10;
                                        casino_x = W_X-(139+10);

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
                                        playerTakeOpportunity = false;
                                        nextBtn->finish();
                                        break;
                                    }
                                }
                                message->selectcard();
toexit:
                                break;
                            }
                            else
                            {

                                for(int j=0; j<myList->getSize(); j++)
                                {
                                    card[j].setHighlighted(false);
                                }
                                twoHighlighted = 0;
                                player_x = 10;
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

                                strokeman = AI;
                                strokeBtn->aistroke();
                                nextBtn->next();
                            }
                        }
                        else  // stroke of ai
                        {
                            //ai throws cards
                            aiTakeOpportunity = true;
                            for (int i=0; i<aiList->getSize(); i++)
                            {
                                for (int j=0; j<aiList->getSize(); j++)
                                {
                                    if ((i!=j)&&(aiList->getIndex(i).getValueIdentifier()==aiList->getIndex(j).getValueIdentifier())&&(aiList->getIndex(i).getQueenOfSpades()==false)&&(aiList->getIndex(j).getQueenOfSpades()==false))
                                    {
                                        if (j>i)
                                        {
                                            aiList->deleteIndex(j);
                                            aiList->deleteIndex(i);
                                        }
                                        else
                                        {
                                            aiList->deleteIndex(i);
                                            aiList->deleteIndex(j);
                                        }
                                        aiTakeOpportunity = false;
                                        goto ai_take;
                                    }
                                }
                            }
ai_take:
                            if (aiList->isEmpty()) //check to empty
                            {
                                break;
                            }
                            //ai choose my card
                            int ai_rand_toChoose = rand() % (myList->getSize());
                            int ai_rand_toPut = rand() % (aiList->getSize());
                            aiList->addIndex(ai_rand_toPut, myList->deleteIndex(ai_rand_toChoose));
                            if (aiTakeOpportunity==true)
                            {
                                //ai throws cards second time
                                for (int i=0; i<aiList->getSize(); i++)
                                {
                                    for (int j=0; j<aiList->getSize(); j++)
                                    {
                                        if ((i!=j)&&(aiList->getIndex(i).getValueIdentifier()==aiList->getIndex(j).getValueIdentifier())&&(aiList->getIndex(i).getQueenOfSpades()==false)&&(aiList->getIndex(j).getQueenOfSpades()==false))
                                        {
                                            if (j>i)
                                            {
                                                aiList->deleteIndex(j);
                                                aiList->deleteIndex(i);
                                            }
                                            else
                                            {
                                                aiList->deleteIndex(i);
                                                aiList->deleteIndex(j);
                                            }
                                            goto ai_draw;
                                        }
                                    }
                                }
                            }
ai_draw:
                            player_x = 10; //default position of player of x coordinate
                            casino_x = W_X-(139+10); //default position of casino of x coordinate

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
                            strokeman = PLAYER;
                            strokeBtn->mystroke();
                            throwOpportunity = true;
                            playerTakeOpportunity = true;
                            nextBtn->take();
                            break;
                        }
                    }
                }
                if((event.mouseButton.button == sf::Mouse::Right)&&(finish==false))
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
        window.draw(backgroundspr);
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
        if (messageIncluded == true)
        {
            window.draw(message->sprite);
        }
        window.draw(nextBtn->sprite);
        window.draw(strokeBtn->sprite);
        if (myList->getSize()==0)  //check to win
        {
            resultBtn->win();
            finish = true;
        }
        if (aiList->getSize()==0)  //check to lose
        {
            resultBtn->lose();
            finish = true;
        }
        if (finish)
        {
            window.draw(resultBtn->sprite);
        }
        window.display();
    } // first loop
}
