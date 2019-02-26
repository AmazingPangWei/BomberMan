#include "monster3.h"

Monster3::Monster3(QWidget *parent):Monster(parent)
{
    movie =  new QMovie();
    speed = 15;
    pix.load(":/new/prefix1/素材/第一关怪物（左）.png");
    this->setPixmap(pix);
}
void Monster3::RightMove()
{
    pix.load(":/new/prefix1/素材/第一关怪物（右）.png");
    this->setPixmap(pix);
    this->move(this->x()+speed,this->y());
}
void Monster3::LeftMove()
{
    pix.load(":/new/prefix1/素材/第一关怪物（左）.png");
    this->setPixmap(pix);
    this->move(this->x()-speed,this->y());
}
void Monster3::UpMove()
{
    this->move(this->x(),this->y()-speed);
}
void Monster3::DownMove()
{
    this->move(this->x(),this->y()+speed);
}
void Monster3::Dead()
{
    movie->setFileName(":/new/prefix1/素材/死亡.gif");
    setMovie(movie);
    movie->start();
}
