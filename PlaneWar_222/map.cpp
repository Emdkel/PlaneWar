#include "map.h"

Map::Map()
{
    map.load(MAP_PATH);
    y = 0;
}

int Map::getY() {
    return y;
}

void Map::setY(int posY) {
    y = posY;
}

void Map::updateY() {
    if(y == MAP_HEIGHT) { //如果图片到达画面底部了
        y = -MAP_HEIGHT + MAP_RATES; //则把图片放上去，注意还要加上它本应该下移的距离
        return;
    }
    y += MAP_RATES;
}

QPixmap& Map::getImg() {
    return map;
}
