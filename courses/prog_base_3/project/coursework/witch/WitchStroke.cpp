#include "WitchStroke.h"

WitchStroke::WitchStroke(){
    this->height = 72;
    this->width = 816;
    this->posX = 10;
    this->posY = W_Y-10-216-5-72;
}

bool WitchStroke::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void WitchStroke::mystroke(){
    this->texture.loadFromFile("textures/witchyourturn.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void WitchStroke::aistroke(){
    this->texture.loadFromFile("textures/witchaistroke.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

