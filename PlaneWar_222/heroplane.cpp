#include"heroplane.h"

HeroPlane::HeroPlane()
{
    heroIMG.load(HEROPLANE_PATH);
    x = MAP_WIDTH * 0.5 - heroIMG.width() * 0.5; //初始化坐标
    y = MAP_HEIGHT - heroIMG.height() - 35;
    mRect.setRect(x, y, heroIMG.width(), heroIMG.height());
    triggerInterval = 0;
    countBomb = 0;
}

int HeroPlane::getX() const {
    return x;
}

int HeroPlane::getY() const {
    return y;
}

QPixmap& HeroPlane::getImg() {
    return heroIMG;
}

void HeroPlane::moveLeft() {
    x -= HERO_PLANE_HORIZONTAL_INCREMENT;
}

void HeroPlane::moveRight() {
    x += HERO_PLANE_HORIZONTAL_INCREMENT;
}

void HeroPlane::moveDown() {
    y += HERO_PLANE_VERTICAL_INCREMENT;
}

void HeroPlane::moveUp() {
    y -= HERO_PLANE_VERTICAL_INCREMENT;
}

void HeroPlane::updatePosition(int key) {
    switch(key)
    {
    case Qt::Key_Up:
        moveUp();
        break;
    case Qt::Key_Down:
        moveDown();
        break;
    case Qt::Key_Left:
        moveLeft();
        break;
    case Qt::Key_Right:
        moveRight();
        break;
    }
    if(y > (MAP_HEIGHT - heroIMG.height()))
        y = MAP_HEIGHT - heroIMG.height();
    if(y < 0)
        y = 0;
    if(x < 0)
        x = 0;
    if(x > (MAP_WIDTH - heroIMG.width()))
        x = MAP_WIDTH - heroIMG.width();
    mRect.moveTo(x, y);
}

void HeroPlane::shoot()
{
    if(triggerInterval < BULLET_TRIGGER_INTERVAL) {
        triggerInterval++;
        return;
    }
    int i = 0;
    for(i=0; i<BULLETS_NUM; i++) {
        if(bullets[i].isFree())
        {
            bullets[i].setEmployed();
            bullets[i].setXY(this->x + heroIMG.width()/2 - 10, this->y);
            triggerInterval = 0;
            break;
        }
    }
}

void HeroPlane::bulletsFly() {
    for(int i=0; i<BULLETS_NUM; i++) {
        if(!bullets[i].isFree())
            bullets[i].updatePosition();
    }
}

void HeroPlane::hitCheck(QVector<EnemyPlane*> enemies)
{
    for(int i=0; i<ENEMIES_NUM; i++)
    {
        if(!enemies[i]->isFree()){
            if(this->mRect.intersects(enemies[i]->mRect)){
                this->hp--;
                enemies[i]->hpDecrease();
            }
            for(int j=0; j<2; j++){
                if(!enemies[i]->bullets[j].isFree() && enemies[i]->bullets[j].mRect.intersects(this->mRect)){
                    hp--;
                    enemies[i]->bullets[j].setFree();
                }
            }
        }

    }
    for(int i=0;i<BULLETS_NUM; i++)
    {
        if(!bullets[i].isFree())
        {
            for(int j=0; j<ENEMIES_NUM; j++)
            {
                if(!enemies[j]->isFree()){
                    if(enemies[j]->mRect.intersects(bullets[i].mRect)){
                        enemies[j]->hpDecrease();
                        bullets[i].setFree();
                        break;
                    }
                }
            }
        }
    }
}

int HeroPlane::getHp() const{
    return hp;
}

void HeroPlane::startBomb()
{
    if(hp<=0 && countBomb==0){
        bomb.setEmployed();
        countBomb++;
    }
}

void HeroPlane::continueBomb()
{
    if(!bomb.isFree())
        bomb.updateInfo();
}

void HeroPlane::init()
{
    shoot();
    bulletsFly();
    startBomb();
    continueBomb();
}










