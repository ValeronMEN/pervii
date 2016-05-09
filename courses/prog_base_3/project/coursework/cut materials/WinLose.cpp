#include "WinLose.h"

WinLose::WinLose(){
    this->posX = 0;
    this->posY = 0;
    this->height = 768;
    this->width = 1002;
    this->texture.loadFromFile("textures/winwin.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)0, (float)0, (float)1002, (float)768));
    this->sprite.setPosition(0, 0);
}

bool WinLose::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}
