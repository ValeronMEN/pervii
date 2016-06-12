#include <SFML/Graphics.hpp>
#include "StartButton.h"
#include "Drunkard.h"
#include "Jack.h"
#include "Witch.h"
#include "Pig.h"
#include "Chicken.h"
#include "StartAsk.h"

using namespace sf;

int quations(int * language, bool * guide){
    sf::RenderWindow window(sf::VideoMode(400, 300), "I want to ask you", sf::Style::Close);
    window.setPosition(sf::Vector2i(750, 310));

    sf::Image image;
    image.loadFromFile("textures/mainIco.png");
    window.setIcon(179, 179, image.getPixelsPtr());

    StartAsk * yes = new StartAsk(0, 100);
    StartAsk * no = new StartAsk(200, 100);
    yes->guide();
    no->guideAbs();

    sf::Texture quation;
    sf::Sprite quationSp;
    quation.loadFromFile("textures/mainGuide.png");
    quationSp.setTexture(quation);

    bool guideS = true;
    bool lan = false;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                return 1;
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                if (yes->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    if (guideS){
                        guideS = false;
                        lan = true;
                        quation.loadFromFile("textures/mainLan.png");
                        quationSp.setTexture(quation);
                        yes->ukrainian();
                        no->english();
                        *guide = true;
                        break;
                    }
                    if (lan){
                        *language = 1;
                        return 0;
                    }
                }
                if (no->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    if (guideS){
                        *guide = false;
                        return 0;
                    }
                    if (lan){
                        *language = 0;
                        return 0;
                    }
                }
            }
        }
        window.clear();
        window.draw(yes->sprite);
        window.draw(no->sprite);
        window.draw(quationSp);
        window.display();
    }
    return 0;
}

int main(){
    int language;
    bool guide;

    if (quations(&language, &guide)==1){
        return 0;
    }

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
                    Witch * witch = new Witch();
                    window.setVisible(0);
                    witch->language = language;
                    witch->guide = guide;
                    witch->start();
                    window.setVisible(1);
                }
                if (drunkardButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    Drunkard * drunkard = new Drunkard();
                    window.setVisible(0);
                    drunkard->language = language;
                    drunkard->guide = guide;
                    drunkard->start();
                    window.setVisible(1);
                }
                if (pigButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    Pig * pig = new Pig();
                    window.setVisible(0);
                    pig->language = language;
                    pig->guide = guide;
                    pig->start();
                    window.setVisible(1);
                }
                if (chickenButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    Chicken * chicken = new Chicken();
                    window.setVisible(0);
                    chicken->language = language;
                    chicken->guide = guide;
                    chicken->start();
                    window.setVisible(1);
                }
                if (jackButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    Jack * jack = new Jack();
                    window.setVisible(0);
                    jack->language = language;
                    jack->guide = guide;
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
