#include "JackCard.h"

JackCard::JackCard(){
    this->posX = 0;
    this->posY = 0;
    this->width = 139;
    this->height = 216;
    this->visible = true;
    this->valueIdentifier = -1;
}

bool JackCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

short int JackCard::getValueIdentifier(){
	return valueIdentifier;
}

std::string JackCard::getImagePath(){
	return imagePath;
}

short int JackCard::getColorIdentifier(){
	return colorIdentifier;
}

void JackCard::setValueIdentifier(short int valueInput){
	valueIdentifier = valueInput;
}

void JackCard::setImagePath(std::string pathInput){
	imagePath = pathInput;
}

void JackCard::setColorIdentifier(short int id){
	colorIdentifier = id;
}

void JackCard::setTexture(){
    this->texture.loadFromFile("textures/JackCardFaces.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(139*(this->valueIdentifier)), (float)(216 * (this->colorIdentifier)), (float)139, (float)216));
}
