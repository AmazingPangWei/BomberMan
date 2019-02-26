#include "boomup.h"

BoomUp::BoomUp(QWidget *parent) :
    QLabel(parent)
{
    resize(35,35);
    pix.load(":/new/prefix1/素材/增加炸弹道具卡.png");
    setPixmap(pix);
}
