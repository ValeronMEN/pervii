#include "JackMore.h"

JackMore::JackMore(){
    this->height = 432;
    this->width = 300;
    this->posX = 0;
    this->posY = 904-height;
    this->texture.loadFromFile("textures/jackmore.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool JackMore::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
