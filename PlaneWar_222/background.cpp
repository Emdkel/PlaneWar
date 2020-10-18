#include "background.h"

BackGround::BackGround()
{
    map1.setY(-MAP_HEIGHT);
    map2.setY(0);
}

void BackGround::updatePosition() {
    map1.updateY();
    map2.updateY();
}

