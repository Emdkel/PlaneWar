#ifndef ELEMENT_H
#define ELEMENT_H

#include <QPixmap>
#include <QRect>

class Element
{
public:
    QPixmap img;
    QRect mRect;
    int x, y;
    bool mFree;

public:
    Element();
    virtual void updatePosition()=0;
    int getX();
    int getY();
    void setXY(int x, int y);
    void setFree();
    void setEmployed();
    bool isFree();
    QPixmap& getImg();
};

#endif // ELEMENT_H
