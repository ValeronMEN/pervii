#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pig.h"

void Pig::start()
{
    sf::RenderWindow window(sf::VideoMode(P_X, P_Y), "Pig");

    sf::Music music;
    if (!music.openFromFile("music/pyramid.ogg"))
    {
        return; // error
    }
    //music.play();

    sf::Texture background;
    background.loadFromFile("textures/pigPyramid.png");
    sf::Sprite backgroundspr;
    backgroundspr.setTexture(background);

    PigDeck * deck = new PigDeck();
    deck->randomize();
    PigCard * card = new PigCard();
    PigCard * card2 = new PigCard();
    *card = deck->getCard();
    *card2 = deck->getCard();
    card->setTexture();
    card2->setTexture();
    card->sprite.setPosition(450, 450);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            //if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
            //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
        }
        window.clear(sf::Color(0,115,0));
        window.draw(backgroundspr);
        window.draw(card->sprite);
        window.draw(card2->sprite);
        window.display();
    }
}
