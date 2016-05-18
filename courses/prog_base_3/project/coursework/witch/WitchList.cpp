#include "WitchList.h"

WitchList::WitchList(){
    this->size = 0;
}

void WitchList::addIndex(int index, WitchCard myCard){
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

void WitchList::addLast(WitchCard myCard){
    card[this->size] = myCard;
    this->size++;
}

WitchCard WitchList::deleteIndex(int index){
    WitchCard toDelete = card[index];
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

WitchCard WitchList::getIndex(int index){
    return card[index];
}

bool WitchList::isEmpty(){
    if (this->size == 0){
        return true;
    }
    else{
        return false;
    }
}

int WitchList::getSize(){
    return size;
}
