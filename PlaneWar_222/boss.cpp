#include "boss.h"
#include <QMessageBox>

Boss::Boss()
{
    img.load(ENEMY_PATH3);
    mFree = false;
    mRect.setRect(10, -80, img.width(), img.height());
    x = 10;
    y = -80;
    hp = BOSS_HP;
    triggerInterval = 0;
    direction = true;
    for(int i=0; i<2; i++){
        bullets[i].changeType();
    }
}

void Boss::updatePosition()
{
    if(hp <= 0){
        QMessageBox::information(NULL, "飞机大战", "游戏胜利，您战胜了敌人！");
        emit bossFall();
    }
    if(y < img.height() + 5){
        y += ENEMY_PLANE_INCREMENT;
        return;
    }
    if(direction)
        x += BOSS_INCREMENT;
    else
        x -= BOSS_INCREMENT;
    if(x < 5){
        x += BOSS_INCREMENT;
        direction = true;
    }
    if(x > MAP_WIDTH-img.width()){
        x -= BOSS_INCREMENT;
        direction = false;
    }
    mRect.moveTo(x, y);
}

void Boss::shoot()
{
    if(y < img.height() + 5)
        return;
    if(triggerInterval < ENEMY_BULLET_TRIGGER_INTERVAL) {
        triggerInterval++;
        return;
    }
    int i = 0;
    for(i=0; i<BULLETS_NUM; i++) {
        if(bullets[i].isFree())
        {
            bullets[i].setEmployed();
            bullets[i].setXY(this->x + img.width()/2 - 10, this->y);
            triggerInterval = 0;
            break;
        }
    }
}

void Boss::bulletFly()
{
    for(int i=0; i<ENEMY_BULLETS_NUM; i++){
        bullets[i].updatePositionBoss();
    }
}
