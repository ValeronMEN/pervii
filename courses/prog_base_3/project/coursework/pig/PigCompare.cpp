#include "PigCompare.h"

PigCompare::PigCompare(){
    this->height = 200;
    this->width = 200;
    this->posX = 0;
    this->posY = 0;
}

bool PigCompare::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void PigCompare::setPosition(int x, int y, int compare){
    this->posX = x;
    this->posY = y;
    if (compare == 0){
        this->texture.loadFromFile("textures/pigCompare.png");
    }
    else if (compare == 1){
        this->texture.loadFromFile("textures/pigCompareM.png");
    }
    else if (compare == 2){
        this->texture.loadFromFile("textures/pigCompareE.png");
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
