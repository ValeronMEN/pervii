#include "WitchThrow.h"

WitchThrow::WitchThrow(){
    this->height = 139;
    this->width = 139;
    this->posX = 10+139+20;
    this->posY = 10+216+82+80,5;
    this->texture.loadFromFile("textures/witchthrow.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool WitchThrow::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
