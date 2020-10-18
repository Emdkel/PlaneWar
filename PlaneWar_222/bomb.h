#ifndef BOMB_H
#define BOMB_H

#include <QVector>
#include <QPixmap>

class Bomb
{
private:
    QVector<QPixmap> bombPics;
    int x, y;
    bool mFree;
    int record; //爆炸时间间隔
    int interval;

public:
    Bomb();
    void updateInfo(); //更新索引信息
    int getX();
    int getY();
    void setXY(int x,int y);
    void setEmployed();
    QPixmap& getImg();
    bool isFree();
    void setFree();
};

#endif // BOMB_H
