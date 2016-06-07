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
    this->texture.loadFromFile("textures/pigCards.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)139, (float)216));
}
