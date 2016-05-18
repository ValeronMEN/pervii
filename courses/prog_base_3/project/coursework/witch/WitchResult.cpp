#include "WitchResult.h"

WitchResult::WitchResult(){
    this->height = 300;
    this->width = 308;
    this->posX = 10+139+20+139;
    this->posY = 10+216+10+72;
    this->texture.loadFromFile("textures/witchloading.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool WitchResult::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void WitchResult::win(){
    this->texture.loadFromFile("textures/witchwin.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void WitchResult::lose(){
    this->texture.loadFromFile("textures/witchlose.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
