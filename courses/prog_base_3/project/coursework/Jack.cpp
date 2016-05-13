#include "Jack.h"

using namespace sf;

void Jack::game(RenderWindow * win, int bank, int oneRate)
{
    win->clear(sf::Color(0,115,0));
    Color * color = new Color(0, 0, 0, 255);
    sf::Font myfont;
    myfont.loadFromFile("fonts/MIDDST__.TTF");
    char text[BUFFER_CONST];

    sf::Text myMoney;
    myMoney.setPosition(420 , J_Y-316);
    myMoney.setColor(*color);
    myMoney.setScale(2, 2);
    myMoney.setFont(myfont);
    itoa(bank, text, 10);
    myMoney.setString(text);

    sf::Text myRate;
    myRate.setPosition(420 , J_Y-100);
    myRate.setColor(*color);
    myRate.setScale(2, 2);
    myRate.setFont(myfont);
    itoa(oneRate, text, 10);
    myRate.setString(text);

    JackMoney * money = new JackMoney();
    JackRate * rate = new JackRate();
    JackMore * more = new JackMore();
    JackOpen * open = new JackOpen();

    JackDeck * deck = new JackDeck();
    JackCard player[6];
    JackCard casino[6];

    deck->randomize();

    for (int i=0; i<2; i++){
        player[i] = deck->getCard();
        casino[i] = deck->getCard();
    }

    player[0].sprite.setPosition(10 , 246);
    player[0].setTexture();
    casino[0].sprite.setPosition(10 , 10);
    casino[0].setTexture();
    player[1].sprite.setPosition(159 , 246);
    player[1].setTexture();

    JackBackCard * bc1 = new JackBackCard();
    bc1->sprite.setPosition(159, 10);


    while(win->isOpen())
    {
        sf::Event event;
        while(win->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                win->close();
            }
            if ((event.type == sf::Event::MouseButtonPressed)&&(event.mouseButton.button == sf::Mouse::Left))
            {
                //if (witchButton->isPressed(event.mouseButton.x, event.mouseButton.y)){
            }
        }
        win->clear(sf::Color(0,115,0));
        win->draw(money->sprite);
        win->draw(rate->sprite);
        win->draw(more->sprite);
        win->draw(open->sprite);
        win->draw(player[0].sprite);
        win->draw(player[1].sprite);
        win->draw(casino[0].sprite);
        win->draw(bc1->sprite);
        win->draw(myMoney);
        win->draw(myRate);
        win->display();
    }
}

void Jack::start()
{
    sf::RenderWindow jackWindow(sf::VideoMode(J_X, J_Y), "21 points");

    // set buttons
    JackBet * bet = new JackBet();
    JackMoney * money = new JackMoney();
    JackRate * rate = new JackRate();
    JackLaunch * launch = new JackLaunch();

    //set values of my money and my rate
    int bank = 100;
    int oneBet = 5;
    int oneRate = 0;

    Color * color = new Color(0, 0, 0, 255);
    sf::Font myfont;
    myfont.loadFromFile("fonts/MIDDST__.TTF");
    char text[BUFFER_CONST];

    sf::Text myMoney;
    myMoney.setPosition(420 , J_Y-316);
    myMoney.setColor(*color);
    myMoney.setScale(2, 2);
    myMoney.setFont(myfont);
    itoa(bank, text, 10);
    myMoney.setString(text);

    sf::Text myRate;
    myRate.setPosition(420 , J_Y-100);
    myRate.setColor(*color);
    myRate.setScale(2, 2);
    myRate.setFont(myfont);
    itoa(oneRate, text, 10);
    myRate.setString(text);

    //main loop

    while(jackWindow.isOpen()){
        sf::Event event;

        while(jackWindow.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                jackWindow.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    if (launch->isPressed(event.mouseButton.x, event.mouseButton.y)){
                        game(&jackWindow, bank, oneRate);
                    }
                    if (bet->isPressed(event.mouseButton.x, event.mouseButton.y)){
                        if (bank == 0){
                            break;
                        }
                        oneRate += oneBet;
                        bank -= oneBet;
                        itoa(bank, text, 10);
                        myMoney.setString(text);
                        itoa(oneRate, text, 10);
                        myRate.setString(text);
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right){
                    if (bet->isPressed(event.mouseButton.x, event.mouseButton.y)){
                        if (oneRate == 0){
                            break;
                        }
                        oneRate -= oneBet;
                        bank += oneBet;
                        itoa(bank, text, 10);
                        myMoney.setString(text);
                        itoa(oneRate, text, 10);
                        myRate.setString(text);
                    }
                }
            }
        }
        jackWindow.clear(sf::Color(0,115,0));
        jackWindow.draw(bet->sprite);
        jackWindow.draw(money->sprite);
        jackWindow.draw(rate->sprite);
        jackWindow.draw(launch->sprite);
        jackWindow.draw(myMoney);
        jackWindow.draw(myRate);
        jackWindow.display();
    }
}


