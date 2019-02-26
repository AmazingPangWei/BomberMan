#include "monster2.h"

Monster2::Monster2(QWidget *parent):Monster(parent)
{
    movie =  new QMovie();
    speed = 10;
    pix.load(":/new/prefix1/素材/第一关怪物（左）.png");
    this->setPixmap(pix);
}
void Monster2::RightMove()
{
    pix.load(":/new/prefix1/素材/第一关怪物（右）.png");
    this->setPixmap(pix);
    this->move(this->x()+speed,this->y());
}
void Monster2::LeftMove()
{
    pix.load(":/new/prefix1/素材/第一关怪物（左）.png");
    this->setPixmap(pix);
    this->move(this->x()-speed,this->y());
}
void Monster2::UpMove()
{
    this->move(this->x(),this->y()-speed);
}
void Monster2::DownMove()
{
    this->move(this->x(),this->y()+speed);
}
void Monster2::Dead()
{
    movie->setFileName(":/new/prefix1/素材/死亡.gif");
    setMovie(movie);
    movie->start();
}
