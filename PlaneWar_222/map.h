#ifndef MAP_H
#define MAP_H

#include<QPixmap>
#include"config.h"

class Map
{
private:
    QPixmap map; //背景图像
    int y; //图像坐标

public:
    Map();
    int getY();
    void setY(int posY); //设置坐标
    void updateY(); //更新纵坐标
    QPixmap& getImg();
};

#endif // MAP_H
