#include "Card.h"

Card::Card(){
    this->posX = 0;
    this->posY = 0;
    this->width = 91;
    this->height = 128;
    this->visible = true;
    this->valueIdentifier = -1;
}

bool Card::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

short int Card::getValueIdentifier(){
	return valueIdentifier;
}

std::string Card::getImagePath(){
	return imagePath;
}

short int Card::getColorIdentifier(){
	return colorIdentifier;
}

void Card::setValueIdentifier(short int valueInput){
	valueIdentifier = valueInput;
}

void Card::setImagePath(std::string pathInput){
	imagePath = pathInput;
}

void Card::setColorIdentifier(short int id){
	colorIdentifier = id;
}

void Card::setTexture(){
    this->texture.loadFromFile("textures/CardsBig.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(1+139*(this->valueIdentifier)), (float)(1+193 * (this->colorIdentifier)), (float)138, (float)192 ));
}
