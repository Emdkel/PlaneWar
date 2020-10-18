#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QRect>
#include "config.h"
#include "element.h"

class Bullet:public Element
{
private:

public:
    Bullet();
    void updatePosition();
    void updatePositionEnemy();
    void updatePositionBoss();
    void changeType();
};

#endif // BULLET_H
