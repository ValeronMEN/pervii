#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Chicken.h"

void Chicken::start(){
    sf::RenderWindow window(sf::VideoMode(C_X, C_Y), "Chicken", sf::Style::Close);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            //if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){

        }
        window.clear();
        //window.draw(witchButton->sprite);
        window.display();
    }
    return;
}
