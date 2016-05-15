#include "Drunkard.h"
#include <queue>
#include <windows.h>

using namespace sf;

void Drunkard::drawDecks()
{
    backCardTex.loadFromFile("textures/BackCard.png");
    backCardTex.setSmooth(true);

    backCardSpr.setTexture(backCardTex);
    backCardSpr.setPosition(432, 759);

    backCardSpr180.setTexture(backCardTex);
    backCardSpr180.setPosition(432, 19);
}

void Drunkard::start()
{
    sf::RenderWindow drunkardWindow(sf::VideoMode(D_X, D_Y), "Drunkard");
    ContinueButton * continueBtn = new ContinueButton();
    DrunkardReturn * returnBtn = new DrunkardReturn();
    std::queue<Card> myQueue;
    std::queue<Card> aiQueue;
    std::queue<Card> *firstQueue;
    std::queue<Card> *secondQueue;
    firstQueue = &myQueue;
    secondQueue = &aiQueue;
    Deck * myDeck = new Deck();
    drawDecks();
    myDeck->randomize();

    int i=0;
    while(i<36)
    {
        myQueue.push(myDeck->getCard());
        i++;
        aiQueue.push(myDeck->getCard());
        i++;
    }

    int strokeman = rand() % 2;
    if (strokeman == 1)
    {
        firstQueue = &aiQueue;
        secondQueue = &myQueue;
    }

    Card * card1f = new Card();
    Card * card1s = new Card();
    Card * card2f = new Card();
    Card * card2s = new Card();
    Card * card3f = new Card();
    Card * card3s = new Card();

    bool visible2fs = false;
    bool visible3fs = false;
    bool finish = false;

    sf::Font myfont;
    myfont.loadFromFile("fonts/MIDDST__.TTF");
    sf::Text mySize;
    sf::Text aiSize;
    mySize.setPosition(590 , 840);
    aiSize.setPosition(590 , 95);
    mySize.setFont(myfont);
    aiSize.setFont(myfont);
    char textSize[BUFFER_CONST];

    while(drunkardWindow.isOpen())
    {
        sf::Event event;

        while(drunkardWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                drunkardWindow.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left))
            {
                if ((returnBtn->isPressed(event.mouseButton.x, event.mouseButton.y))&&(finish==true))
                {
                    drunkardWindow.close();
                }
                if ((continueBtn->isPressed(event.mouseButton.x, event.mouseButton.y))&&(finish==false))
                {
                    itoa(myQueue.size(),textSize,10);
                    mySize.setString(textSize);
                    itoa(aiQueue.size(),textSize,10);
                    aiSize.setString(textSize);

                    visible2fs = false;
                    visible3fs = false;

                    // first round of first and second players

                    *card1f = firstQueue->front();
                    *card1s = secondQueue->front();
                    card1f->setTexture();
                    card1s->setTexture();
                    firstQueue->pop();
                    secondQueue->pop();

                    // set positions of f and s cards

                    if (firstQueue == &myQueue)
                    {
                        card1f->sprite.setPosition(266, 549);
                        card1s->sprite.setPosition(598, 229);
                    }
                    else
                    {
                        card1f->sprite.setPosition(598, 229);
                        card1s->sprite.setPosition(266, 549);
                    }

                    // compare 1f and 1s

                    if((card1f->valueIdentifier > card1s->valueIdentifier)||(secondQueue->empty()))
                    {
                        firstQueue->push(*card1f);
                        firstQueue->push(*card1s);
                        break;
                    }
                    if((card1f->valueIdentifier < card1s->valueIdentifier)||(firstQueue->empty()))
                    {
                        secondQueue->push(*card1f);
                        secondQueue->push(*card1s);
                        break;
                    }
                    if(card1f->valueIdentifier == card1s->valueIdentifier)
                    {
                        // second round

                        *card2f = firstQueue->front();
                        *card2s = secondQueue->front();
                        firstQueue->pop();
                        secondQueue->pop();
                        visible2fs = true;

                        // set positions of first and second cards

                        backCardSpr2f.setTexture(backCardTex);
                        backCardSpr2f.setPosition(312, 485);
                        backCardSpr2s.setTexture(backCardTex);
                        backCardSpr2s.setPosition(552, 293);

                        // isEmpty

                        if(firstQueue->empty()||secondQueue->empty())
                        {
                            firstQueue->push(*card1f);
                            firstQueue->push(*card1s);
                            firstQueue->push(*card2f);
                            firstQueue->push(*card2s);
                            break;
                        }
                        else
                        {
                            *card3f = firstQueue->front();
                            *card3s = secondQueue->front();
                            firstQueue->pop();
                            secondQueue->pop();
                            visible3fs = true;

                            card3f->setTexture();
                            card3s->setTexture();

                            if (firstQueue == &myQueue)
                            {
                                card3f->sprite.setPosition(358, 421);
                                card3s->sprite.setPosition(506, 357);
                            }
                            else
                            {
                                card3s->sprite.setPosition(358, 421);
                                card3f->sprite.setPosition(506, 357);
                            }
                            if (card1f->valueIdentifier>=card1s->valueIdentifier)
                            {
                                firstQueue->push(*card1f);
                                firstQueue->push(*card1s);
                                firstQueue->push(*card2f);
                                firstQueue->push(*card2s);
                                firstQueue->push(*card3f);
                                firstQueue->push(*card3s);
                                break;
                            }
                            else
                            {
                                secondQueue->push(*card1f);
                                secondQueue->push(*card1s);
                                secondQueue->push(*card2f);
                                secondQueue->push(*card2s);
                                secondQueue->push(*card3f);
                                secondQueue->push(*card3s);
                                break;
                            }
                        }
                    }

                }
            }
        }
        if(myQueue.size()==36)
        {
            continueBtn->win();
            finish = true;
        }
        if(aiQueue.size()==36)
        {
            continueBtn->lose();
            finish = true;
        }
        drunkardWindow.clear(sf::Color(0,115,0));
        drunkardWindow.draw(backCardSpr);
        drunkardWindow.draw(backCardSpr180);
        drunkardWindow.draw(continueBtn->sprite);
        drunkardWindow.draw(card1f->sprite);
        drunkardWindow.draw(card1s->sprite);
        drunkardWindow.draw(mySize);
        drunkardWindow.draw(aiSize);
        if (visible2fs)
        {
            drunkardWindow.draw(backCardSpr2f);
            drunkardWindow.draw(backCardSpr2s);
        }
        if (visible3fs)
        {
            drunkardWindow.draw(card3f->sprite);
            drunkardWindow.draw(card3s->sprite);
        }
        if (finish)
        {
            drunkardWindow.draw(returnBtn->sprite);
        }
        drunkardWindow.display();
    }
}
