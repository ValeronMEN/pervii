#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Chicken.h"

char * Chicken::getWannaText(int points){
    if (points==1){
        return "ACE";
    }
    else if (points == 2){
        return "SECUNDA";
    }
    else if (points == 3){
        return "TERTIA";
    }
    else if (points == 4){
        return "QUARTA";
    }
    else if (points == 5){
        return "QUINTA";
    }
    else if (points == 6){
        return "SEXTA";
    }
    else if (points == 7){
        return "SEPTIMA";
    }
    else if (points == 8){
        return "OCTAVA";
    }
    else if (points == 9){
        return "NONA";
    }
    else if (points == 10){
        return "DECIMA";
    }
    else if (points == 11){
        return "JACK";
    }
    else if (points == 12){
        return "QUEEN";
    }
    else if (points == 13){
        return "KING";
    }
    else{
        return NULL;
    }
}

void Chicken::fonts(int strokeman)
{
    aggFont.loadFromFile("fonts/Agg.ttf");
    myFont.loadFromFile("fonts/Push.ttf");

    wannaText.setPosition(30+31+139+25+125, 30);
    wannaText.setColor(Color::Blue);
    wannaText.setFont(aggFont);
    wannaText.setCharacterSize(50);

    strokeText.setPosition(500-150 , C_Y - 100);
    strokeText.setColor(Color::Blue);
    strokeText.setFont(aggFont);
    strokeText.setCharacterSize(50);

    mySize.setPosition(30+139+5, 30+216/2-20);
    mySize.setColor(Color::White);
    mySize.setFont(myFont);
    mySize.setCharacterSize(30);

    aiSize.setPosition(C_X-139-30-50, C_Y-30-216/2-20);
    aiSize.setColor(Color::White);
    aiSize.setFont(myFont);
    aiSize.setCharacterSize(30);

    mySize.setString("52");
    aiSize.setString("52");
    wannaText.setString("I wanna see ACE!");
    if (strokeman == AI){
        strokeText.setString("Enemy stroke...");
    }
    else{
        strokeText.setString("Your stroke...");
    }

    background.loadFromFile("textures/upGround1.png");
    backgroundspr.setTexture(background);
}

void Chicken::start(){
    sf::RenderWindow window(sf::VideoMode(C_X, C_Y), "I WANNA", sf::Style::Close);
    image.loadFromFile("textures/upIco.png");
    window.setIcon(179, 179, image.getPixelsPtr());

    ChickenDeck * myDeck = new ChickenDeck();
    myDeck->randomize();
    ChickenDeck * aiDeck = new ChickenDeck();
    aiDeck->randomize();
    ChickenCard * middleCard = new ChickenCard();
    middleCard->sprite.setPosition(430.5, C_Y-100);
    ChickenCard * myCard = new ChickenCard();
    myCard->sprite.setPosition(30, 30+216+30);
    ChickenCard * aiCard = new ChickenCard();
    aiCard->sprite.setPosition(C_X-139-30, C_Y-30-216-216-30);

    ChickenNext * nextBtn = new ChickenNext();
    nextBtn->next();

    ChickenBackCard * myDeckSkin = new ChickenBackCard();
    ChickenBackCard * aiDeckSkin = new ChickenBackCard();
    aiDeckSkin->sprite.setPosition(30, 30);
    myDeckSkin->sprite.setPosition(C_X-30-139, C_Y-30-216);
    aiDeckSkin->setTexture();
    myDeckSkin->setTexture();

    std::queue<ChickenCard> myQueue;
    std::queue<ChickenCard> aiQueue;
    std::queue<ChickenCard> *firstQueue;
    std::queue<ChickenCard> *secondQueue;

    int strokeman = rand() % 2;
    if (strokeman == AI)
    {
        firstQueue = &aiQueue;
        secondQueue = &myQueue;
    }
    else{
        firstQueue = &myQueue;
        secondQueue = &aiQueue;
    }
    fonts(strokeman);

    for (int i=0; i<52; i++){
        myQueue.push(myDeck->getCard());
        aiQueue.push(aiDeck->getCard());
    }
    bool compareB = false;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left)){
                if (nextBtn->isPressed(event.mouseButton.x, event.mouseButton.y)){
                }
            }
        }
        window.clear(sf::Color(0,115,0));
        window.draw(backgroundspr);
        window.draw(myDeckSkin->sprite);
        window.draw(aiDeckSkin->sprite);
        if (compareB == true){
            window.draw(myCard->sprite);
            window.draw(aiCard->sprite);
        }
        window.draw(nextBtn->sprite);
        window.draw(mySize);
        window.draw(aiSize);
        window.draw(wannaText);
        window.draw(strokeText);
        window.display();
    }
    return;
}
