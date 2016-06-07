#include <SFML/Audio.hpp>
#include "Jack.h"
#include <windows.h>

int Jack::game(RenderWindow * win, int oneRate)
{
    win->clear(sf::Color(0,115,0));
    Color * color = new Color(0, 0, 0, 255);
    sf::Font myfont;
    myfont.loadFromFile("fonts/MIDDST__.TTF");
    char text[BUFFER_CONST];
    int player_points = 0, casino_points = 0, casino_x=10, player_x = 10, player_size = 2, casino_size = 1;
    bool finish = false;
    bool ai_ready = false;
    bool bcvisible = true;
    bool playeroverflow = false;
    int ai_rand;

    sf::Text myRate;
    myRate.setPosition(420 , J_Y-100);
    myRate.setColor(*color);
    myRate.setScale(2, 2);
    myRate.setFont(myfont);

    sf::Text myPoints;
    myPoints.setPosition(420 , J_Y-316);
    myPoints.setColor(*color);
    myPoints.setScale(2, 2);
    myPoints.setFont(myfont);

    sf::Text enemyPoints;
    enemyPoints.setPosition(120, J_Y-144);
    enemyPoints.setColor(*color);
    enemyPoints.setScale(3, 3);
    enemyPoints.setFont(myfont);

    JackMoney * money = new JackMoney();
    JackRate * rate = new JackRate();
    JackMore * more = new JackMore();
    JackOpen * openbtn = new JackOpen();
    JackPoints * pointsbtn = new JackPoints();
    JackMessage * message = new JackMessage();
    JackBackCard * bc = new JackBackCard();

    JackDeck * deck = new JackDeck();
    deck->randomize();
    JackCard player[7];
    JackCard casino[7];

    for (int i=0; i<2; i++)
    {
        player[i] = deck->getCard();
        casino[i] = deck->getCard();
        player_points += player[i].getPoints();
        casino_points += casino[i].getPoints();
    }

    itoa(oneRate, text, 10);
    myRate.setString(text);
    itoa(player_points, text, 10);
    myPoints.setString(text);

    player[0].sprite.setPosition(player_x , 246);
    player[0].setTexture();
    player_x+=139/2;
    casino[0].sprite.setPosition(casino_x , 10);
    casino[0].setTexture();
    casino_x+=139/2;

    player[1].sprite.setPosition(player_x , 246);
    player[1].setTexture();
    player_x+=139/2;

    bc->sprite.setPosition(casino_x, 10);

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
                if ((openbtn->isPressed(event.mouseButton.x, event.mouseButton.y))&&(finish==true))
                {
                    if ((playeroverflow == true)||((player_points < casino_points)&&(casino_points <= 21))){
                        return 0;
                    }
                    if ((player_points > casino_points)||(casino_points > 21))
                    {
                        return 1;
                    }
                    else{
                        return -1;
                    }
                }
                if ((openbtn->isPressed(event.mouseButton.x, event.mouseButton.y))&&(finish==false))
                {
                    casino[1].sprite.setPosition(casino_x , 10);
                    casino[1].setTexture();
                    casino_x+=139/2;
                    casino_size++;
                    bcvisible = false;
                    while (ai_ready==false)
                    {
                        if (casino_points>=21)
                        {
                            break;
                        }
                        if (casino_points>19)
                        {
                            ai_rand = rand()%20;
                            if (ai_rand>=19)
                            {
                                casino[casino_size] = deck->getCard();
                                casino_points += casino[casino_size].getPoints();
                                casino[casino_size].sprite.setPosition(casino_x , 10);
                                casino[casino_size].setTexture();
                                casino_x+=139/2;
                                casino_size++;
                            }
                            break;
                        }
                        if (casino_points>17)
                        {
                            ai_rand = rand()%20;
                            if (ai_rand>=17)
                            {
                                casino[casino_size] = deck->getCard();
                                casino_points += casino[casino_size].getPoints();
                                casino[casino_size].sprite.setPosition(casino_x , 10);
                                casino[casino_size].setTexture();
                                casino_x+=139/2;
                                casino_size++;
                                continue;
                            }
                            break;
                        }
                        if (casino_points>15)
                        {
                            ai_rand = rand()%20;
                            if (ai_rand>=15)
                            {
                                casino[casino_size] = deck->getCard();
                                casino_points += casino[casino_size].getPoints();
                                casino[casino_size].sprite.setPosition(casino_x , 10);
                                casino[casino_size].setTexture();
                                casino_x+=139/2;
                                casino_size++;
                                continue;
                            }
                            break;
                        }
                        if (casino_points>10)
                        {
                            ai_rand = rand()%20;
                            if (ai_rand>=7)
                            {
                                casino[casino_size] = deck->getCard();
                                casino_points += casino[casino_size].getPoints();
                                casino[casino_size].sprite.setPosition(casino_x , 10);
                                casino[casino_size].setTexture();
                                casino_x+=139/2;
                                casino_size++;
                                continue;
                            }
                            break;
                        }
                        casino[casino_size] = deck->getCard();
                        casino_points += casino[casino_size].getPoints();
                        casino[casino_size].sprite.setPosition(casino_x , 10);
                        casino[casino_size].setTexture();
                        casino_x+=139/2;
                        casino_size++;
                        continue;
                    }
                    more->enemypoints();
                    openbtn->exit();
                    itoa(casino_points, text, 10);
                    enemyPoints.setString(text);
                    if ((player_points > casino_points)||(casino_points > 21))
                    {
                        message->win();
                    }
                    if ((player_points < casino_points)&&(casino_points <= 21))
                    {
                        message->lose();
                    }
                    if (player_points == casino_points){
                        message->draw();
                    }
                    finish=true;
                }
                if ((more->isPressed(event.mouseButton.x, event.mouseButton.y))&&(finish==false))
                {
                    player[player_size] = deck->getCard();
                    player_points += player[player_size].getPoints();
                    player[player_size].sprite.setPosition(player_x , 246);
                    player[player_size].setTexture();
                    player_x+=139/2;
                    player_size++;

                    itoa(player_points, text, 10);
                    myPoints.setString(text);
                }
            }
        }
        if (player_points > 21)
        {
            message->overflow();
            openbtn->exit();
            playeroverflow = true;
            finish=true;
        }
        win->clear(sf::Color(0,115,0));
        win->draw(money->sprite);
        win->draw(rate->sprite);
        win->draw(more->sprite);
        win->draw(openbtn->sprite);
        win->draw(pointsbtn->sprite);
        win->draw(casino[0].sprite);
        for(int i=0; i<player_size; i++)
        {
            win->draw(player[i].sprite);
        }
        for(int i=0; i<casino_size; i++)
        {
            win->draw(casino[i].sprite);
        }
        if (bcvisible)
        {
            win->draw(bc->sprite);
        }
        win->draw(myPoints);
        win->draw(enemyPoints);
        win->draw(myRate);
        if (finish)
        {
            win->draw(message->sprite);
        }
        win->display();
    }
}

void Jack::start()
{
    sf::Music music;
    if (!music.openFromFile("music/music1.ogg")){
        return; // error
    }
    music.play();

    sf::Texture ivanovBackGr;
    sf::Sprite ivanovBackGrSp;
    ivanovBackGr.loadFromFile("textures/ivanovPr.png");
    ivanovBackGrSp.setTexture(ivanovBackGr);
    ivanovBackGrSp.setPosition(77.5, 50);

    sf::RenderWindow jackWindow(sf::VideoMode(J_X, J_Y), "21 points");

    // set buttons
    JackBet * bet = new JackBet();
    JackMoney * money = new JackMoney();
    JackRate * rate = new JackRate();
    JackLaunch * launch = new JackLaunch();

    //set values of my money and my rate
    int bank = 500;
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

    while(jackWindow.isOpen())
    {
        sf::Event event;

        while(jackWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                jackWindow.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (launch->isPressed(event.mouseButton.x, event.mouseButton.y)&&(oneRate!=0))
                    {
                        int result = game(&jackWindow, oneRate);
                        if(result == 0)
                        {
                            oneRate = 0;
                            itoa(oneRate, text, 10);
                            myRate.setString(text);
                        }
                        else{
                            if(result == 1){
                                bank += oneRate;
                            }
                            bank += oneRate;
                            oneRate = 0;
                            itoa(bank, text, 10);
                            myMoney.setString(text);
                            itoa(oneRate, text, 10);
                            myRate.setString(text);
                        }
                    }
                    if (bet->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        if (bank == 0)
                        {
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
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (bet->isPressed(event.mouseButton.x, event.mouseButton.y))
                    {
                        if (oneRate == 0)
                        {
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
        jackWindow.draw(ivanovBackGrSp);
        jackWindow.display();
    }
}


