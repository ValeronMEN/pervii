#include "ChickenList.h"

ChickenList::ChickenList(){
    this->size = 0;
}

void ChickenList::addIndex(int index, ChickenCard myCard){
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

void ChickenList::addLast(ChickenCard myCard){
    card[this->size] = myCard;
    this->size++;
}

ChickenCard ChickenList::deleteIndex(int index){
    ChickenCard toDelete = card[index];
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

ChickenCard ChickenList::getIndex(int index){
    return card[index];
}

bool ChickenList::isEmpty(){
    if (this->size == 0){
        return true;
    }
    else{
        return false;
    }
}

int ChickenList::getSize(){
    return size;
}
