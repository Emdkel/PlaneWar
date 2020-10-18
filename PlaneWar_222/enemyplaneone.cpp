#include "enemyplaneone.h"

EnemyPlaneOne::EnemyPlaneOne()
{
    img.load(ENEMY_PATH);
    mFree = true;
    mRect.setRect(0, 0, img.width(), img.height());
    y = img.height();
    hp = ENEMY_HP;
}

void EnemyPlaneOne::updatePosition()
{
    y += ENEMY_PLANE_INCREMENT;
    if(y > MAP_HEIGHT)
        this->setFree();
    mRect.moveTo(x, y);
}

