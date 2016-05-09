#include "Jack.h"

using namespace sf;

void Jack::start(){
    sf::RenderWindow jackWindow(sf::VideoMode(700, 700), "21 points");

    while(jackWindow.isOpen()){
        sf::Event event;
        while(jackWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                jackWindow.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
            }
        }
        jackWindow.clear(sf::Color(0,115,0));
        //window.draw(witchButton->sprite);
        jackWindow.display();
    }
}
