#include <SFML/Graphics.hpp>
#include "StartButton.h"
#include "Drunkard.h"
#include "Jack.h"
#include "Witch.h"
#include "Pig.h"
#include "Chicken.h"

using namespace sf;

int main(){
    sf::RenderWindow window(sf::VideoMode(1638, 900), "Card games", sf::Style::Close);
    window.setPosition(sf::Vector2i(150, 60));

    sf::Image image;
    image.loadFromFile("textures/mainIco.png");
    window.setIcon(179, 179, image.getPixelsPtr());

    StartButton* witchButton = new StartButton(0);
    StartButton* drunkardButton = new StartButton(1);
    StartButton* pigButton = new StartButton(2);
    StartButton* chickenButton = new StartButton(3);
    StartButton* jackButton = new StartButton(4);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.setVisible(0);
                    Witch * witch = new Witch();
                    witch->start();
                    window.setVisible(1);
                }
                if (drunkardButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.setVisible(0);
                    Drunkard * drunkard = new Drunkard();
                    drunkard->start();
                    window.setVisible(1);
                }
                if (pigButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.setVisible(0);
                    Pig * pig = new Pig();
                    pig->start();
                    window.setVisible(1);
                }
                if (chickenButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.setVisible(0);
                    Chicken * chicken = new Chicken();
                    chicken->start();
                    window.setVisible(1);
                }
                if (jackButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.setVisible(0);
                    Jack * jack = new Jack();
                    jack->start();
                    window.setVisible(1);
                }
            }
        }
        window.clear();
        window.draw(witchButton->sprite);
        window.draw(drunkardButton->sprite);
        window.draw(pigButton->sprite);
        window.draw(chickenButton->sprite);
        window.draw(jackButton->sprite);
        window.display();
    }

    return 0;
}
