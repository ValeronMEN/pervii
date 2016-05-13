#include "JackBackCard.h"

JackBackCard::JackBackCard(){
    this->posX = 0;
    this->posY = 0;
    this->width = 139;
    this->height = 216;
    this->visible = true;

    this->texture.loadFromFile("textures/jackBackTex.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
}
