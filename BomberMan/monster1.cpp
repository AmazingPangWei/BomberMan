#include "monster1.h"

Monster1::Monster1(QWidget *parent):Monster(parent)
{
    timer = new QTimer(this);
    movie =  new QMovie();
    speed = 5;
    pix.load(":/new/prefix1/素材/第一关怪物（左）.png");
    this->setPixmap(pix);
}
void Monster1::RightMove()
{
    pix.load(":/new/prefix1/素材/第一关怪物（右）.png");
    this->setPixmap(pix);
    this->move(this->x()+speed,this->y());
}
void Monster1::LeftMove()
{
    pix.load(":/new/prefix1/素材/第一关怪物（左）.png");
    this->setPixmap(pix);
    this->move(this->x()-speed,this->y());
}
void Monster1::UpMove()
{
    this->move(this->x(),this->y()-speed);
}
void Monster1::DownMove()
{
    this->move(this->x(),this->y()+speed);
}
void Monster1::Dead()
{
    movie->setFileName(":/new/prefix1/素材/怪物死亡.gif");
    setMovie(movie);
    movie->start();
    islive = 0;  //死亡
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(clear()));
}
void Monster1::clear(){
    this->hide();
}

