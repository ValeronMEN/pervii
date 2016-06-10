#include "ChickenNext.h"

ChickenNext::ChickenNext(){
    this->height = 100;
    this->width = 278;
    this->posX = 0;
    this->posY = C_Y-100;
}

bool ChickenNext::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void ChickenNext::next(){
    this->texture.loadFromFile("textures/upNext.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void ChickenNext::win(){
    this->texture.loadFromFile("textures/upWin.png");
    this->sprite.setTexture(this->texture);
}

void ChickenNext::lose(){
    this->texture.loadFromFile("textures/upLose.png");
    this->sprite.setTexture(this->texture);
}
