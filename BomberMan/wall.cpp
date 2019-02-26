#include "wall.h"

Wall::Wall(QWidget *parent) :
    QLabel(parent)
{
    resize(35,35);
    pix.load(":/new/prefix1/素材/爆炸砖块.png");
    setPixmap(pix);
}
void Wall::Dead()
{

}
