#include "StartButton.h"

StartButton::StartButton(int number){
    this->height = 180;
    this->width = 1638;
    this->posX = 0;
    this->posY = height*number;
    this->texture.loadFromFile("textures/startbuttons.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)0, (float)height*number, (float)1638, (float)180 ));
    this->sprite.setPosition(posX, posY);
}

bool StartButton::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
