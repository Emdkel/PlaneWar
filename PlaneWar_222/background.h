#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QPixmap>
#include <map.h>
#include "config.h"

class BackGround
{
public:
    Map map1; //图片1
    Map map2; //图片2

public:
    BackGround();
    void updatePosition(); //更新图片坐标
};

#endif // BACKGROUND_H

