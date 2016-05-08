#include "Drunkard.h"
#include <queue>

using namespace sf;

void Drunkard::drawDecks(){
    backCardTex.loadFromFile("textures/BackCard.png");
    backCardTex.setSmooth(true);
    backCardSpr.setTexture(backCardTex);
    backCardSpr.setPosition(276, 600);

    backCardTex180.loadFromFile("textures/BackCard2.png");
    backCardTex180.setSmooth(true);
    backCardSpr180.setTexture(backCardTex180);
    backCardSpr180.setPosition(276, 100);
}

void Drunkard::start(){
    sf::RenderWindow window(sf::VideoMode(D_X, D_Y), "Drunkard");
    ContinueButton * continueBtn = new ContinueButton();

    std::queue<Card> myQueue;
    std::queue<Card> aiQueue;

    Deck * myDeck = new Deck();
    //myDeck->randomize();

/*
    int i=0;
    while(i<36){
        myQueue.push(myDeck->getCard());
        i++;
        aiQueue.push(myDeck->getCard());
        i++;
    }
    */

    drawDecks();

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                //d
            }
        }
        window.clear(sf::Color(0,115,0));
        window.draw(backCardSpr);
        window.draw(backCardSpr180);
        window.draw(continueBtn->sprite);
        window.display();
    }
}
