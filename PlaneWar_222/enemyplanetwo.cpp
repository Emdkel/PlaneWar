#include "enemyplanetwo.h"
#include <QTime>
#include <QtGlobal>

EnemyPlaneTwo::EnemyPlaneTwo()
{
    img.load(ENEMY_PATH2);
    mFree = true;
    mRect.setRect(0, 0, img.width(), img.height());
    x = -10;
    y = -10;
    hp = ENEMY_HP;
    for(int i=0; i<2; i++){
        bullets[i].changeType();
    }
}

void EnemyPlaneTwo::updatePosition()
{
    y += ENEMY_PLANE_INCREMENT;
    if(y > MAP_HEIGHT){
        this->setFree();
        for(int i=0; i<ENEMY_BULLETS_NUM; i++){
            bullets[i].setFree();
        }
    }
    mRect.moveTo(x, y);
}

void EnemyPlaneTwo::shoot()
{
    qsrand(time(NULL)); //设置随机数种子
    int shootHeight = (qrand() %26) + 25; //产生随机数
    if(bullets[0].isFree() && bullets[1].isFree() && y>=shootHeight){
        bullets[0].setXY(this->x, this->y+img.height());
        bullets[1].setXY(this->x+img.width()-10, this->y+img.height());
        bullets[0].setEmployed();
        bullets[1].setEmployed();
    }
}

void EnemyPlaneTwo::bulletFly()
{
    if(!bullets[0].isFree())
        bullets[0].updatePositionEnemy();
    if(!bullets[1].isFree())
        bullets[1].updatePositionEnemy();
}
