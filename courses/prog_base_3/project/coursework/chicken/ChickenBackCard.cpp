#include "ChickenBackCard.h"

ChickenBackCard::ChickenBackCard(){
    this->width = 139;
    this->height = 216;
}

bool ChickenBackCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void ChickenBackCard::setCoordinates(int x, int y){
    this->posX = x;
    this->posY = y;
}

void ChickenBackCard::setTexture(){
    this->texture.loadFromFile("textures/upBack.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, (float)139, (float)216));
}
