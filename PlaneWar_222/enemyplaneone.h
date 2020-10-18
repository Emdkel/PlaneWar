#ifndef ENEMYPLANEONE_H
#define ENEMYPLANEONE_H

#include <QPixmap>
#include <QRect>
#include "enemyplane.h"
#include "config.h"
#include "bomb.h"

class EnemyPlaneOne:public EnemyPlane
{
public:
    EnemyPlaneOne();
    void updatePosition();

};

#endif // ENEMYPLANEONE_H
