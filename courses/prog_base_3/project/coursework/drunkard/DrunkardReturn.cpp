#include "DrunkardReturn.h"

DrunkardReturn::DrunkardReturn(){
    this->height = 256;
    this->width = 256;
    this->posX = 0;
    this->posY = 0;
    this->texture.loadFromFile("textures/drunkardreturn.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool DrunkardReturn::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
