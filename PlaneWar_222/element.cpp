#include "element.h"

Element::Element()
{
    mFree = true;
}

int Element::getX(){
    return x;
}

int Element::getY(){
    return y;
}

void Element::setXY(int x, int y){
    this->x = x;
    this->y = y;
}

bool Element::isFree(){
    return mFree;
}

void Element::setFree(){
    mFree = true;
}

void Element::setEmployed(){
    mFree = false;
}

QPixmap& Element::getImg(){
    return img;
}

