#include "JackMessage.h"

JackMessage::JackMessage(){
    this->height = 216;
    this->width = 300;
    this->posX = J_X-319;
    this->posY = 246;
}

bool JackMessage::isPressed(float x, float y){
    if ((x > this->posX) && ( x < this->posX + this->width) && (y > this->posY) && (y < this->posY + this->height))
        return true;
    else
        return false;
}

void JackMessage::win(){
    this->texture.loadFromFile("textures/jackwin.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void JackMessage::lose(){
    this->texture.loadFromFile("textures/jacklose.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void JackMessage::overflow(){
    this->texture.loadFromFile("textures/jackoverflow.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}

void JackMessage::draw(){
    this->texture.loadFromFile("textures/jackdraw.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX, posY);
}
