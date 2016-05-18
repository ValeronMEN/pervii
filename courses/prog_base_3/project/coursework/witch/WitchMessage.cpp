#include "WitchMessage.h"

WitchMessage::WitchMessage(){
    this->height = 72;
    this->width = 816;
    this->posX = 50;
    this->posY = 10+216+5;
}

bool WitchMessage::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void WitchMessage::selectcard(){
    this->texture.loadFromFile("textures/witchmselectcard.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
