#ifndef ENEMYPLANETWO_H
#define ENEMYPLANETWO_H

#include "enemyplane.h"
#include "bullet.h"
#include "config.h"

class EnemyPlaneTwo:public EnemyPlane
{
public:
    EnemyPlaneTwo();
    void updatePosition();
    void shoot();
    void bulletFly();
};

#endif // ENEMYPLANETWO_H
