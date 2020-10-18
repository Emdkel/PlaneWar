#include "bullet.h"

Bullet::Bullet()
{
    x = -10;
    y = -10;
    img.load(BULLET_PATH);
    mFree = true;
    mRect.setRect(0, 0, img.width(), img.height());
}

void Bullet::updatePosition(){
    y -= BULLET_SPEED;
    if(y < 0)
        this->setFree();
    mRect.moveTo(this->x, this->y);
}

void Bullet::updatePositionEnemy(){
    y += BULLET_SPEED;
    mRect.moveTo(this->x, this->y);
}

void Bullet::updatePositionBoss(){
    y += BULLET_SPEED;
    if(y >= MAP_HEIGHT)
        this->setFree();
    mRect.moveTo(this->x, this->y);
}

void Bullet::changeType(){
    img.load(BULLET_PATH_ENEMY);
}

