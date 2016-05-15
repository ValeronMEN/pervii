#include "ContinueButton.h"

ContinueButton::ContinueButton(){
    this->height = 256;
    this->width = 256;
    this->posX = D_X-height;
    this->posY = D_Y-width;
    this->texture.loadFromFile("textures/drunkardcontinue.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

bool ContinueButton::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void ContinueButton::win(){
    this->texture.loadFromFile("textures/drunkardwin.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void ContinueButton::lose(){
    this->texture.loadFromFile("textures/drunkardlose.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
