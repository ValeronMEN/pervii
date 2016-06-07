#include "PigTake.h"

PigTake::PigTake(){
    this->height = 250;
    this->width = 250;
    this->posX = 1300-250;
    this->posY = 900-250;
    this->texture.loadFromFile("textures/pigTake.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool PigTake::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
