#include "enemyplane.h"

EnemyPlane::EnemyPlane(QObject *parent) : QObject(parent)
{

}

int EnemyPlane::getHp(){
    return hp;
}

void EnemyPlane::hpDecrease(){
    hp--;
}

