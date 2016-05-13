#include "JackLaunch.h"

JackLaunch::JackLaunch(){
    this->height = 432;
    this->width = 300;
    this->posX = 604;
    this->posY = 904-height;
    this->texture.loadFromFile("textures/jacklaunch.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool JackLaunch::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
