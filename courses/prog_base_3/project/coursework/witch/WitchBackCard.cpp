#include "WitchBackCard.h"

WitchBackCard::WitchBackCard(){
    this->width = 139;
    this->currwidth = 23;
    this->height = 216;
    this->highlighted = false;
}

void WitchBackCard::setHighlighted(bool b){
    this->highlighted = b;
}

bool WitchBackCard::getHighlighted(){
    return this->highlighted;
}

bool WitchBackCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void WitchBackCard::setCoordinates(int x, int y){
    this->posX = x;
    this->posY = y;
}

bool WitchBackCard::isClickedCurr(int x, int y){
    if (((this->posX + 116) < x) && ((this->posX + 139) >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void WitchBackCard::setTexture(){
    this->texture.loadFromFile("textures/jackBackTex.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, (float)139, (float)216));
}

/*
void WitchBackCard::setCutTexture(){
    this->texture.loadFromFile("textures/jackBackTex.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(116, 0, (float)23, (float)216));
}
*/

void WitchBackCard::setCurrTexture(){
    this->texture.loadFromFile("textures/jackBackTexCurr.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, (float)139, (float)216));
}

void WitchBackCard::setCurrCutTexture(){
    this->texture.loadFromFile("textures/jackBackTexCurrCut.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, (float)139, (float)216));
}
