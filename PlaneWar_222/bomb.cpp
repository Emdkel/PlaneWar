#include "bomb.h"
#include "config.h"
#include <QString>

Bomb::Bomb()
{
    for(int i=1; i<BOMB_MAX_INDEX+1; i++){
        QString path = QString(BOMB_PATH).arg(i);
        bombPics.push_back(path);
    }
    record = 0;
    interval = 0;
    mFree = true;
}

void Bomb::setXY(int x, int y){
    this->x = x;
    this->y = y;
}

int Bomb::getX(){
    return x;
}

int Bomb::getY(){
    return y;
}

void Bomb::updateInfo()
{
    if(interval < BOMB_INTERVAL){
        interval++;
        return;
    }
    record++;
    interval = 0;
    if(record >= BOMB_MAX_INDEX){
        mFree = true;
        record = 0;
    }
}

void Bomb::setEmployed(){
    mFree = false;
}

QPixmap& Bomb::getImg(){
    return bombPics[record];
}

bool Bomb::isFree(){
    return mFree;
}

void Bomb::setFree(){
    mFree = true;
}
