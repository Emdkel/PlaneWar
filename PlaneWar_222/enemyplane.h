#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QObject>
#include "element.h"
#include "bullet.h"
#include "config.h"

class EnemyPlane : public QObject, public Element
{
    Q_OBJECT
public:
    int hp;
    Bullet bullets[ENEMY_BULLETS_NUM];

public:
    explicit EnemyPlane(QObject *parent = nullptr);
    void hpDecrease();
    int getHp();
    virtual void shoot(){}
    virtual void bulletFly(){}

signals:
    void fall();
    void bossFall();
};

#endif // ENEMYPLANE_H

