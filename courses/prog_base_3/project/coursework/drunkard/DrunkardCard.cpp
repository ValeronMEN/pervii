#include "DrunkardCard.h"

DrunkardCard::DrunkardCard(){
    this->posX = 0;
    this->posY = 0;
    this->width = 91;
    this->height = 128;
    this->visible = true;
    this->valueIdentifier = -1;
}

bool DrunkardCard::isClicked(int x, int y){
    if ((this->posX < x) && (this->posX + this->width >= x) && (this->posY + this->height > y) && (this->posY < y)){
        return true;
    }
    return false;
}

short int DrunkardCard::getValueIdentifier(){
	return valueIdentifier;
}

short int DrunkardCard::getColorIdentifier(){
	return colorIdentifier;
}

void DrunkardCard::setValueIdentifier(short int valueInput){
	valueIdentifier = valueInput;
}

void DrunkardCard::setColorIdentifier(short int id){
	colorIdentifier = id;
}

void DrunkardCard::setTexture(){
    this->texture.loadFromFile("textures/CardsBig.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect((float)(1+139*(this->valueIdentifier)), (float)(1+193 * (this->colorIdentifier)), (float)138, (float)192 ));
}
