#include "PigTake.h"

PigTake::PigTake(){
    this->height = 250;
    this->width = 250;
    this->posX = 1300-250;
    this->posY = 900-250;
}

void PigTake::start(){
    this->texture.loadFromFile("textures/pigStart.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void PigTake::take(){
    this->texture.loadFromFile("textures/pigTake.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void PigTake::watch(){
    this->texture.loadFromFile("textures/pigWatch.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool PigTake::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void PigTake::win(){
    this->texture.loadFromFile("textures/pigWin.png");
    this->sprite.setTexture(this->texture);
}

void PigTake::lose(){
    this->texture.loadFromFile("textures/pigLose.png");
    this->sprite.setTexture(this->texture);
}

void PigTake::draw(){
    this->texture.loadFromFile("textures/pigDraw.png");
    this->sprite.setTexture(this->texture);
}
