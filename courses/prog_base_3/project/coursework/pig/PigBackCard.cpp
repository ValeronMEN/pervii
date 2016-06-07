#include "PigBackCard.h"

PigBackCard::PigBackCard(){
    this->width = 110.2;
    this->height = 203;
    this->highlighted = false;
}

bool PigBackCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void PigBackCard::setCoordinates(int x, int y){
    this->posX = x;
    this->posY = y;
}

void PigBackCard::setTexture(){
    this->texture.loadFromFile("textures/pigBackCard.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, (float)112, (float)206.25));
}
