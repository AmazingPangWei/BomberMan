#include "fewall.h"


FeWall::FeWall(QWidget *parent) :
    QLabel(parent)
{
    resize(35,35);
    pix.load(":/new/prefix1/素材/硬砖块.png");
    setPixmap(pix);
}
