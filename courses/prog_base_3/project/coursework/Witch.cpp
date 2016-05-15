#include <SFML/Graphics.hpp>
#include "Witch.h"
#include <windows.h>

using namespace sf;

void Witch::start(){
    sf::RenderWindow window(sf::VideoMode(W_X, W_Y), "Witch");
    window.clear(sf::Color(0,115,0));
    window.display();
    WitchDeck * deck = new WitchDeck();
    deck->randomize();

    int player_x = 10;

    WitchList * myList = new WitchList();
    WitchList * aiList = new WitchList();
    WitchList * firstList = myList;
    WitchList * secondList = aiList;

    WitchCard card[36];

    int strokeman = rand() % 2;
    if (strokeman == 1){
        firstList = aiList;
        secondList = myList;
    }
    int i=0;
    while(i<18){
        myList->addIndex(-1, deck->getCard());
        aiList->addIndex(-1, deck->getCard());
        i++;
    }

    for (int i=0; i<myList->getSize(); i++){
        card[i] = myList->getIndex(i);
        card[i].sprite.setPosition(player_x, W_Y-10-216);
        card[i].setCoordinates(player_x, W_Y-10-216);
        if((myList->getSize()-1)==i){
            card[i].setTexture();
        }
        else{
            card[i].setCutTexture();
        }
        player_x += 23;
    }

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            for(int i=0; i<(myList->getSize()-1); i++){
                if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                    if (card[i].isClickedCurr(event.mouseButton.x, event.mouseButton.y)){
                        card[i].setCurrCutTexture();
                    }
                }
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                if (card[myList->getSize()-1].isClicked(event.mouseButton.x, event.mouseButton.y)){
                    card[myList->getSize()-1].setCurrTexture();
                }
            }
        }
        window.clear(sf::Color(0,115,0));
        for (int i=0; i<myList->getSize(); i++){
            window.draw(card[i].sprite);
        }

        //window.draw(witchButton->sprite);
        window.display();
    }
}
