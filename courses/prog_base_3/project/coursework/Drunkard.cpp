#include "Drunkard.h"

void Drunkard::drawDecks()
{
    backCardTex.loadFromFile("textures/BackCard.png");
    backCardTex.setSmooth(true);

    backCardSpr.setTexture(backCardTex);
    backCardSpr.setPosition(432, 759);

    backCardSpr180.setTexture(backCardTex);
    backCardSpr180.setPosition(432, 19);

    myFont.loadFromFile("fonts/shitan.otf");

    strokeText.setPosition(0+10 , D_Y-50);
    strokeText.setColor(sf::Color::White);
    strokeText.setFont(myFont);
    strokeText.setCharacterSize(30);
}

void Drunkard::start()
{
    sf::Music music;
    if (!music.openFromFile("music/model.ogg")){
        return; // error
    }
    music.play();
    music.setLoop(true);

    sf::RenderWindow drunkardWindow(sf::VideoMode(D_X, D_Y), "Britney Beach", sf::Style::Close);
    drunkardWindow.setPosition(sf::Vector2i(450, 15));
    image.loadFromFile("textures/drunkardIco.png");
    drunkardWindow.setIcon(179, 179, image.getPixelsPtr());

    sf::RenderWindow windowGuide(sf::VideoMode(500, 700), "Guide", sf::Style::Titlebar);
    windowGuide.setVisible(false);

    if (guide==true)
    {
        drunkardWindow.setPosition(sf::Vector2i(100, 15));
        windowGuide.setVisible(true);

        windowGuide.setPosition(sf::Vector2i(1370, 170));
        if (language == 1){
            backgroundGuide.loadFromFile("textures/drunkardRules.png");
        }
        else{
            backgroundGuide.loadFromFile("textures/engDrunkardRules.png");
        }
        backgroundsprGuide.setTexture(backgroundGuide);
        windowGuide.draw(backgroundsprGuide);
        windowGuide.display();
    }

    background.loadFromFile("textures/drunkardLoading.png");
    backgroundspr.setTexture(background);
    drunkardWindow.draw(backgroundspr);
    drunkardWindow.display();
    Sleep(3000);

    background.loadFromFile("textures/drunkardpalm.png");
    backgroundspr.setTexture(background);

    DrunkardContinueButton * continueBtn = new DrunkardContinueButton();
    DrunkardReturn * returnBtn = new DrunkardReturn();
    std::queue<DrunkardCard> myQueue;
    std::queue<DrunkardCard> aiQueue;
    std::queue<DrunkardCard> *firstQueue;
    std::queue<DrunkardCard> *secondQueue;

    DrunkardDeck * myDeck = new DrunkardDeck();
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
    else{
        firstQueue = &myQueue;
        secondQueue = &aiQueue;
    }

    DrunkardCard * card1f = new DrunkardCard();
    DrunkardCard * card1s = new DrunkardCard();
    DrunkardCard * card2f = new DrunkardCard();
    DrunkardCard * card2s = new DrunkardCard();
    DrunkardCard * card3f = new DrunkardCard();
    DrunkardCard * card3s = new DrunkardCard();

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
                    if (strokeman == 1){
                        strokeman = 0;
                        strokeText.setString("AI STROKE");
                    }
                    else{
                        strokeman = 1;
                        strokeText.setString("YOUR STROKE");
                    }
                    //set text of size of decks, set false visible to 2f, 2s, 3f, 3s cards
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

                    if (firstQueue == &myQueue) // set positions of 1f and 1s cards
                    {
                        card1f->sprite.setPosition(266, 549);
                        card1s->sprite.setPosition(598, 229);
                    }
                    else
                    {
                        card1f->sprite.setPosition(598, 229);
                        card1s->sprite.setPosition(266, 549);
                    }
                    if ((card1f->getValueIdentifier()==0)&&(card1s->getValueIdentifier()==8)) // compare 1f and 1s with T and 6 vales
                    {
                        firstQueue->push(*card1f);
                        firstQueue->push(*card1s);
                        break;
                    }
                    if ((card1f->getValueIdentifier()==8)&&(card1s->getValueIdentifier()==0)) // compare 1f and 1s with T and 6 vales
                    {
                        secondQueue->push(*card1f);
                        secondQueue->push(*card1s);
                        break;
                    }
                    if((card1f->valueIdentifier > card1s->valueIdentifier)) // compare 1f and 1s
                    {
                        firstQueue->push(*card1f);
                        firstQueue->push(*card1s);
                        break;
                    }
                    if((card1f->valueIdentifier < card1s->valueIdentifier)) // compare 1f and 1s
                    {
                        secondQueue->push(*card1f);
                        secondQueue->push(*card1s);
                        break;
                    }
                    if(card1f->valueIdentifier == card1s->valueIdentifier) // compare 1f and 1s
                    {
                        if(firstQueue->size()==0||secondQueue->size()==0) //check to empty card2f and card2s
                        {
                            firstQueue->push(*card1f);
                            firstQueue->push(*card1s);
                            break;
                        }
                        else
                        {
                            // second round of first and second players
                            *card2f = firstQueue->front();
                            *card2s = secondQueue->front();
                            firstQueue->pop();
                            secondQueue->pop();
                            visible2fs = true;

                            // set positions of 2f and 2s cards
                            backCardSpr2f.setTexture(backCardTex);
                            backCardSpr2f.setPosition(312, 485);
                            backCardSpr2s.setTexture(backCardTex);
                            backCardSpr2s.setPosition(552, 293);

                            if(firstQueue->size()==0||secondQueue->size()==0) //check to empty card3f and card3s
                            {
                                firstQueue->push(*card1f);
                                firstQueue->push(*card1s);
                                firstQueue->push(*card2f);
                                firstQueue->push(*card2s);
                                break;
                            }
                            else
                            {
                                // third round of first and second players
                                *card3f = firstQueue->front();
                                *card3s = secondQueue->front();
                                firstQueue->pop();
                                secondQueue->pop();
                                card3f->setTexture();
                                card3s->setTexture();
                                visible3fs = true;

                                if (firstQueue == &myQueue) // set positions of 3f and 3s cards
                                {
                                    card3f->sprite.setPosition(358, 421);
                                    card3s->sprite.setPosition(506, 357);
                                }
                                else
                                {
                                    card3s->sprite.setPosition(358, 421);
                                    card3f->sprite.setPosition(506, 357);
                                }

                                if ((card3f->getValueIdentifier()==0)&&(card3s->getValueIdentifier()==8)) // compare 3f and 3s with T and 6 vales
                                {
                                    firstQueue->push(*card1f);
                                    firstQueue->push(*card1s);
                                    firstQueue->push(*card2f);
                                    firstQueue->push(*card2s);
                                    firstQueue->push(*card3f);
                                    firstQueue->push(*card3s);
                                    break;
                                }
                                if ((card3f->getValueIdentifier()==8)&&(card3s->getValueIdentifier()==0)) // compare 3f and 3s with T and 6 vales
                                {
                                    secondQueue->push(*card1f);
                                    secondQueue->push(*card1s);
                                    secondQueue->push(*card2f);
                                    secondQueue->push(*card2s);
                                    secondQueue->push(*card3f);
                                    secondQueue->push(*card3s);
                                    break;
                                }
                                if (card3f->valueIdentifier>=card3s->valueIdentifier) // compare 3f and 3s
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
        drunkardWindow.draw(backgroundspr);
        drunkardWindow.draw(backCardSpr);
        drunkardWindow.draw(backCardSpr180);
        drunkardWindow.draw(continueBtn->sprite);
        drunkardWindow.draw(card1f->sprite);
        drunkardWindow.draw(card1s->sprite);
        drunkardWindow.draw(mySize);
        drunkardWindow.draw(aiSize);
        drunkardWindow.draw(strokeText);
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
