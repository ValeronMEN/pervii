#include "JackBet.h"

JackBet::JackBet(){
    this->height = 432;
    this->width = 300;
    this->posX = 0;
    this->posY = 904-height;
    this->texture.loadFromFile("textures/jackbet.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool JackBet::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
