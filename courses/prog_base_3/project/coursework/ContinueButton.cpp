#include "ContinueButton.h"

ContinueButton::ContinueButton(){
    this->height = 256;
    this->width = 256;
    this->posX = D_X-height;
    this->posY = D_Y-width;
    this->texture.loadFromFile("textures/continue.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool ContinueButton::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
