#include "PigBackCard.h"

PigBackCard::PigBackCard(){
    this->width = 139;
    this->height = 216;

    this->texture.loadFromFile("textures/pigCards.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*2), (float)(1+ 216 * 4), (float)139, (float)216));
}

bool PigBackCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}
