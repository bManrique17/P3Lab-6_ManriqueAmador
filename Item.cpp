#include "Item.h"

Item::Item(){}

Item::Item(int x,int y){
    this->x = x;
    this->y = y;
}

int Item::getX(){
    return x;
}

int Item::getY(){
    return y;
}

void Item::setX(int _x){
    x = _x;
}

void Item::setY(int _y){
    y = _y;
}
