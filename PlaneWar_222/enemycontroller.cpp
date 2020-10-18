#include "enemycontroller.h"
#include <QTime>
#include <QtGlobal>
#include "enemyplanetwo.h"
#include "boss.h"
#include <QSound>

EnemyController::EnemyController()
{
    interval = 0;
    fallenNum = 0;
    mChange = false;
    enemies.push_back(new EnemyPlaneOne);
    enemies.push_back(new EnemyPlaneOne);
    enemies.push_back(new EnemyPlaneOne);
}

void EnemyController::shoot()
{
    if(interval < ENEMY_INTERVAL){
        interval++;
        return;
    }
    for(int i=0; i<ENEMIES_NUM; i++){
        if(enemies[i]->isFree()){
            for(int j=0; j<ENEMY_BULLETS_NUM; j++){
                enemies[i]->bullets[j].setFree();
            }
            enemies[i]->setEmployed();
            interval = 0;
            qsrand(time(NULL)); //设置随机数种子
            int x = qrand() % (MAP_WIDTH - ENEMY_WIDTH - 20); //产生随机数
            enemies[i]->setXY(x, -ENEMY_HEIGHT);
            break;
        }
    }
}

void EnemyController::enemiesFly()
{
    for(int i=0; i<ENEMIES_NUM; i++) {
        if(!enemies[i]->isFree())
            enemies[i]->updatePosition();
    }
}

void EnemyController::startBomb()
{
    for(int i=0; i<ENEMIES_NUM; i++)
    {
        if(enemies[i]->getHp() <= 0)
        {
            emit enemies[i]->fall();
            for(int j=0; j<BOMB_NUM; j++)
            {
                if(bombs[j].isFree()){
                    bombs[j].setXY(enemies[i]->getX(), enemies[i]->getY());
                    bombs[j].setEmployed();
                    QSound::play(SOUND_BOMB);
                    break;
                }
            }
            enemies[i]->setFree();
            enemies[i]->hp = ENEMY_HP;
        }
    }
}

void EnemyController::bombContinue()
{
    for(int i=0; i<BOMB_NUM; i++)
    {
        if(!bombs[i].isFree())
            bombs[i].updateInfo();
    }
}

void EnemyController::fallenNumIncrease(){
    fallenNum++;
}

void EnemyController::setChange(){
    if(fallenNum == 5){
        enemies.pop_back();
        enemies.push_back(new EnemyPlaneTwo);
        enemies.remove(1);
        enemies.push_back(new EnemyPlaneTwo);
    }
    if(fallenNum == 15){
        enemies.pop_back();
        enemies.push_back(new Boss);
        emit bossShowUp();
    }
}

void EnemyController::shootBullet(){
    for(int i=0; i<ENEMIES_NUM; i++){
        if(enemies[i]->getHp() > 0)
            enemies[i]->shoot();
    }
}

void EnemyController::bulletFly(){
    for(int i=0; i<ENEMIES_NUM; i++){
        enemies[i]->bulletFly();
    }
}

void EnemyController::init(){
    shoot();
    enemiesFly();
    startBomb();
    bombContinue();
    setChange();
    shootBullet();
    bulletFly();
}
