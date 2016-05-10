#include "Jack.h"

using namespace sf;

void Jack::start(){
    sf::RenderWindow jackWindow(sf::VideoMode(J_X, J_Y), "21 points");

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

void Jack::game(RenderWindow * win){
    win->clear(sf::Color(0,115,0));

    while(win->isOpen()){
        sf::Event event;
        while(win->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                win->close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
            }
        }
        win->clear(sf::Color(0,115,0));
        //window.draw(witchButton->sprite);
        win->display();
    }
}
