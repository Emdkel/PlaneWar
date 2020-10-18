#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include "config.h"
#include <QTimer>
#include <background.h>
#include <QPainter>
#include <heroplane.h>
#include <QKeyEvent>
#include "enemycontroller.h"
#include "enemyplaneone.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;
    QTimer* timer;
    BackGround bg;
    HeroPlane heroPlane;
    EnemyPlaneOne enemies[3];
    EnemyController enemyController;
    int keyPressed;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event); //重写绘图事件
    void keyPressEvent(QKeyEvent *event); //监听键盘按下事件
    void initScene(); //初始化场景

signals:
    void startGame();

private slots:
    void updatePositionHero(); //更新窗口中所有元素的坐标
    void updatePositionEnemies();
    void EnemiesShowUp();
    void restart();
    void addSlot();
};
#endif // WIDGET_H

