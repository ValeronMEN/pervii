#include <SFML/Graphics.hpp>
#include "StartButton.h"
#include "Drunkard.h"

using namespace sf;

int main(){
    sf::RenderWindow window(sf::VideoMode(1638, 900), "Card games");

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
                    //Witch * witch = new Witch();
                    //witch->start();
                }
                if (drunkardButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    Drunkard * drunkard = new Drunkard();
                    drunkard->start();
                }
                if (pigButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.close();
                }
                if (chickenButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.close();
                }
                if (jackButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
                    window.close();
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

    /*
    sf::Texture cardTexture;
    Sprite background;
    Texture backTexture;
    backTexture.loadFromFile("textures/startbuttons.png");
    background.setTexture(backTexture);
    background.setPosition(0, 0);
    window.draw(background);
    window.display();
    */
    //background.setScale((float)1648/400, (float)900/ 300);


    /*
     while (this->win->isOpen())
    {
        Event event;
        while (this->win->pollEvent(event))
        {
            if (event.type == Event::Closed)
                this->win->close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (callButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        this->callButton->called(0, bet);
                        this->nextRound();
                    }
                    if (foldButton->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        this->nextDistribution();
                    }

                }
            }


        }
        */
