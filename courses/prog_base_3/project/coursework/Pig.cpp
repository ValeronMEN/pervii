#include <SFML/Graphics.hpp>
#include "Pig.h"

void Pig::start(){
    sf::RenderWindow window(sf::VideoMode(1638, 900), "Pig");

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            //if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
        }
        window.clear(sf::Color(0,115,0));
        //window.draw(witchButton->sprite);
        window.display();
    }
}
