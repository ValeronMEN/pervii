#include "WitchNext.h"

WitchNext::WitchNext(){
    this->height = 139;
    this->width = 139;
    this->posX = 10;
    this->posY = 10+216+82+80,5;
    this->texture.loadFromFile("textures/witchnext.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool WitchNext::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
