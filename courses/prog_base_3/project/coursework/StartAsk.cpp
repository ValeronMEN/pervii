#include "StartAsk.h"

StartAsk::StartAsk(int x, int y){
    this->height = 200;
    this->width = 200;
    this->posX = x;
    this->posY = y;
}

bool StartAsk::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void StartAsk::guide(){
    this->texture.loadFromFile("textures/mainYes.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void StartAsk::guideAbs(){
    this->texture.loadFromFile("textures/mainNo.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void StartAsk::english(){
    this->texture.loadFromFile("textures/mainEng.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void StartAsk::ukrainian(){
    this->texture.loadFromFile("textures/mainUkr.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
