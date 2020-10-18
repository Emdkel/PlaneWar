#ifndef BOSS_H
#define BOSS_H

#include "enemyplane.h"
#include "config.h"

class Boss: public EnemyPlane
{
public:
    int triggerInterval;
    bool direction;

public:
    Boss();
    void updatePosition();
    void shoot();
    void bulletFly();
};

#endif // BOSS_H
