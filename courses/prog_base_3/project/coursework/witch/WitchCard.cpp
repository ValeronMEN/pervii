#include "WitchCard.h"

WitchCard::WitchCard(){
    this->width = 139;
    this->currwidth = 23;
    this->height = 216;
    this->highlighted = false;
}

void WitchCard::setHighlighted(bool b){
    this->highlighted = b;
}

bool WitchCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void WitchCard::setCoordinates(int x, int y){
    this->posX = x;
    this->posY = y;
}

bool WitchCard::isClickedCurr(int x, int y){
    if ((this->posX < x) && (this->posX + this->currwidth >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

short int WitchCard::getValueIdentifier(){
	return valueIdentifier;
}

short int WitchCard::getColorIdentifier(){
	return colorIdentifier;
}

void WitchCard::setValueIdentifier(short int valueInput){
	valueIdentifier = valueInput;
}

void WitchCard::setColorIdentifier(short int id){
	colorIdentifier = id;
}

void WitchCard::setPoints(int p){
	this->points = p;
}

int WitchCard::getPoints(){
	return this->points;
}

void WitchCard::setTexture(){
    this->texture.loadFromFile("textures/JackCardFaces.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)139, (float)216));
}

void WitchCard::setCutTexture(){
    this->texture.loadFromFile("textures/JackCardFaces.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)23, (float)216));
}

void WitchCard::setCurrTexture(){
    this->texture.loadFromFile("textures/CardsBigS.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)139, (float)216));
}

void WitchCard::setCurrCutTexture(){
    this->texture.loadFromFile("textures/CardsBigS.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)23, (float)216));
}
