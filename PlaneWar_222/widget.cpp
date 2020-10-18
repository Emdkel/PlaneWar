#include "widget.h"
#include "ui_widget.h"
#include "config.h"
#include <QProcess>
#include <QSound>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    keyPressed = 0;
    this->initScene();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updatePositionHero(){
    bg.updatePosition();
    heroPlane.init();
}

void Widget::updatePositionEnemies(){
    heroPlane.hitCheck(enemyController.enemies);
    enemyController.init();
}

void Widget::EnemiesShowUp(){
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositionEnemies()));
}

void Widget::initScene(){
    timer = new QTimer();
    timer->setInterval(GAME_RATE);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePositionHero()));
    connect(this, SIGNAL(startGame()), this, SLOT(EnemiesShowUp()));
    for(int i=0; i<ENEMIES_NUM; i++){
        connect(enemyController.enemies[i], SIGNAL(fall()), &enemyController, SLOT(fallenNumIncrease()));
    }
    connect(&enemyController, SIGNAL(bossShowUp()), this, SLOT(addSlot()));
    timer->start();
    QSound::play(SOUND_BACKGROUND);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, bg.map1.getY(), bg.map1.getImg());
    painter.drawPixmap(0, bg.map2.getY(), bg.map2.getImg());
    if(heroPlane.getHp() >= 0){
        painter.drawPixmap(heroPlane.getX(), heroPlane.getY(), heroPlane.getImg());
        for(int i=0; i<BULLETS_NUM; i++) {
            if(!heroPlane.bullets[i].isFree())
                painter.drawPixmap(heroPlane.bullets[i].getX(), heroPlane.bullets[i].getY(), heroPlane.bullets[i].getImg());
        }
    }
    if(!heroPlane.bomb.isFree())
            painter.drawPixmap(heroPlane.getX(), heroPlane.getY(), heroPlane.bomb.getImg());
    for(int i=0; i<ENEMIES_NUM; i++) {
        if(!enemyController.enemies[i]->isFree())
            painter.drawPixmap(enemyController.enemies[i]->getX(), enemyController.enemies[i]->getY(), enemyController.enemies[i]->getImg());
    }
    for(int i=0; i<ENEMIES_NUM; i++) {
        if(!enemyController.enemies[i]->bullets[0].isFree())
            painter.drawPixmap(enemyController.enemies[i]->bullets[0].getX(), enemyController.enemies[i]->bullets[0].getY(), enemyController.enemies[i]->bullets[0].getImg());
        if(!enemyController.enemies[i]->bullets[1].isFree())
            painter.drawPixmap(enemyController.enemies[i]->bullets[1].getX(), enemyController.enemies[i]->bullets[1].getY(), enemyController.enemies[i]->bullets[1].getImg());
    }
    for(int i=0; i<BOMB_NUM; i++) {
        if(!enemyController.bombs[i].isFree())
            painter.drawPixmap(enemyController.bombs[i].getX(), enemyController.bombs[i].getY(), enemyController.bombs[i].getImg());
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    keyPressed++;
    if(keyPressed == 1)
        emit startGame();
    heroPlane.updatePosition(event->key());
}

void Widget::restart()
{
    qApp->quit(); //重启游戏
    QProcess::startDetached(qApp->applicationFilePath(),QStringList());
}

void Widget::addSlot(){
    for(int i=0; i<ENEMIES_NUM; i++){
        connect(enemyController.enemies[i], SIGNAL(bossFall()), this, SLOT(restart()));
    }
}
