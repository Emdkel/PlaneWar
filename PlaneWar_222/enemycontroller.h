#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "enemyplaneone.h"
#include "config.h"
#include "bomb.h"
#include <QVector>

class EnemyController:public QObject
{
    Q_OBJECT
private:
    int interval;
    int fallenNum;
    bool mChange;

public:
    QVector<EnemyPlane*> enemies;
    Bomb bombs[BOMB_NUM];

public:
    EnemyController();
    void shoot();
    void enemiesFly();
    void startBomb();
    void bombContinue();
    void setChange();
    void shootBullet();
    void bulletFly();
    void init();

signals:
    void bossShowUp();

public slots:
    void fallenNumIncrease();
};

#endif // ENEMYCONTROLLER_H
