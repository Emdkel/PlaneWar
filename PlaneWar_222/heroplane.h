#ifndef HEROPLANE_H
#define HEROPLANE_H

#include "config.h"
#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"
#include <QVector>

class HeroPlane
{
private:
    QPixmap heroIMG; //飞机图片
    QRect mRect;
    int x, y; //飞机位置
    int triggerInterval;
    int hp = HERO_HP; //血量
    int countBomb;

public:
    Bullet bullets[BULLETS_NUM]; //弹匣
    Bomb bomb;

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

public:
    HeroPlane();
    QPixmap& getImg();
    int getX() const;
    int getY() const;
    void updatePosition(int key);
    void shoot();
    void bulletsFly();
    void hitCheck(QVector<EnemyPlane*> enemies);
    int getHp() const;
    void startBomb();
    void continueBomb();
    void init();
};

#endif // HEROPLANE_H
