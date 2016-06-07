#include "PigCard.h"

PigCard::PigCard(){
    this->width = 110.2;
    this->height = 203;
}

bool PigCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void PigCard::setCoordinates(int x, int y){
    this->posX = x;
    this->posY = y;
}

short int PigCard::getValueIdentifier(){
	return valueIdentifier;
}

short int PigCard::getColorIdentifier(){
	return colorIdentifier;
}

void PigCard::setValueIdentifier(short int valueInput){
	valueIdentifier = valueInput;
}

void PigCard::setColorIdentifier(short int id){
	colorIdentifier = id;
}

void PigCard::setPoints(int p){
	this->points = p;
}

int PigCard::getPoints(){
	return this->points;
}

void PigCard::setTexture(){
    this->texture.loadFromFile("textures/pigCards3.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(110.2*(this->valueIdentifier)), (float)(203 * (this->colorIdentifier)), (float)110.2, (float)203));
    //this->sprite.setTextureRect(sf::IntRect((float)(165.3*(this->valueIdentifier)), (float)(304.5 * (this->colorIdentifier)), (float)165.3, (float)304.5));
}
