#include "boomtimer.h"

BoomTimer::BoomTimer(QWidget *parent) :
    QLabel(parent)
{
    resize(35,35);
    pix.load(":/new/prefix1/素材/定时炸弹道具卡.png");
    setPixmap(pix);
}
