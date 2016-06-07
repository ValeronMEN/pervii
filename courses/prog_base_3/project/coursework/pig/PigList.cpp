#include "PigList.h"

PigList::PigList(){
    this->size = 0;
}

void PigList::addIndex(int index, PigCard myCard){
    if (index>this->size||index<0){
        index = this->size;
    }
    else{
        for (int i=this->size; i>index; i--){
            card[i] = card[i-1];
        }
    }
    card[index] = myCard;
    this->size++;
}

void PigList::addLast(PigCard myCard){
    card[this->size] = myCard;
    this->size++;
}

PigCard PigList::deleteIndex(int index){
    PigCard toDelete = card[index];
    if ((index+1)==this->size){
        this->size--;
        return toDelete;
    }
    for (int i=index; i<this->size; i++){
        card[i] = card[(i+1)];
    }
    this->size--;
    return toDelete;
}

PigCard PigList::getIndex(int index){
    return card[index];
}

bool PigList::isEmpty(){
    if (this->size == 0){
        return true;
    }
    else{
        return false;
    }
}

int PigList::getSize(){
    return this->size;
}

int PigList::getPoints(){
    int sum=0;
    for (int i=0; i<this->size; i++){
        sum = sum + card[i].getPoints();
    }
    return sum;
}
