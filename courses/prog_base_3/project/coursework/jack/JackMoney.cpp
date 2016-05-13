#include "JackMoney.h"

JackMoney::JackMoney(){
    this->height = 216;
    this->width = 304;
    this->posX = 300;
    this->posY = 904-height*2;
    this->texture.loadFromFile("textures/jackmoney.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool JackMoney::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
