#include "JackOpen.h"

JackOpen::JackOpen(){
    this->height = 432;
    this->width = 300;
    this->posX = 604;
    this->posY = 904-height;
    this->texture.loadFromFile("textures/jackopen.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool JackOpen::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void JackOpen::exit(){
    this->texture.loadFromFile("textures/jackexit.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
