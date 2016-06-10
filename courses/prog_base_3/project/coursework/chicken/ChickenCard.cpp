#include "ChickenCard.h"

ChickenCard::ChickenCard(){
    this->width = 139;
    this->height = 216;
}

bool ChickenCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

void ChickenCard::setCoordinates(int x, int y){
    this->posX = x;
    this->posY = y;
}

short int ChickenCard::getValueIdentifier(){
	return valueIdentifier;
}

short int ChickenCard::getColorIdentifier(){
	return colorIdentifier;
}

void ChickenCard::setValueIdentifier(short int valueInput){
	valueIdentifier = valueInput;
}

void ChickenCard::setColorIdentifier(short int id){
	colorIdentifier = id;
}

void ChickenCard::setPoints(int p){
	this->points = p;
}

int ChickenCard::getPoints(){
	return this->points;
}

void ChickenCard::setTexture(){
    this->texture.loadFromFile("textures/JackCardFaces.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)139, (float)216));
}
