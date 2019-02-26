#include "powerup.h"

PowerUp::PowerUp(QWidget *parent) :
    QLabel(parent)
{
    resize(35,35);
    pix.load(":/new/prefix1/素材/道具卡1.png");
    setPixmap(pix);
}
