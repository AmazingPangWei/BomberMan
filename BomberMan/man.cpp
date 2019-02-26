#include "man.h"

Man::Man(QWidget *parent):QLabel(parent)
{
    speed=5;
    BoomNum=1;
    power=1;
    IsTimer=0;
    IsCrossWall=0;

    right = 1;
    left =1 ;
    up=1;
    down=1;


    movie = new QMovie();
    pix_right.load(":/new/prefix1/右1.png");
    this->setPixmap(pix_right);
}
int Man::GetSpeed()
{
    return speed;
}
int Man::GetBoomNum()
{
    return BoomNum;
}
int Man::GetPower()
{
    return power;
}
void Man::SetSpeed(int speed)
{
    this->speed=speed;
}
void Man::SetBoomNum(int BoomNum)
{
    this->BoomNum=BoomNum;
}
void Man::PowerUp()
{
    power++;
}
void Man::SpeedUp()
{
    speed++;
}
void Man::BoomNumUp()
{
    BoomNum++;
}
void Man::SetBoom() //放炸弹
{
    BoomNum--;

}
void Man::RightMove()
{
//     movie->stop();
//     movie->setFileName(":/new/prefix1/素材/右走.gif");
//     this->setMovie(movie);
 //    movie->start();
 //    this->move(this->x()+speed,this->y());
     if(right == 4)
         right=1;
     if(right==1)
     {
        pix_right.load(":/new/prefix1/右1.png");
        this->setPixmap(pix_right);
        this->move(this->x()+speed,this->y());
        right++;
     }
     else if(right == 2)
     {
         pix_right.load(":/new/prefix1/右2.png");
         this->setPixmap(pix_right);
         this->move(this->x()+speed,this->y());
         right++;
     }
     else if(right == 3)
     {
         pix_right.load(":/new/prefix1/右3.png");
         this->setPixmap(pix_right);
         this->move(this->x()+speed,this->y());
         right++;
     }

}
void Man::LeftMove()
{
    if(left == 4)
        left=1;
    if(left==1)
    {
       pix_left.load(":/new/prefix1/左1.png");
       this->setPixmap(pix_left);
       this->move(this->x()-speed,this->y());
       left++;
    }
    else if(left == 2)
    {
        pix_left.load(":/new/prefix1/左2.png");
        this->setPixmap(pix_left);
        this->move(this->x()-speed,this->y());
        left++;
    }
    else if(left == 3)
    {
        pix_left.load(":/new/prefix1/左3.png");
        this->setPixmap(pix_left);
        this->move(this->x()-speed,this->y());
        left++;
    }
}
void Man::UpMove()
{
    if(up == 4)
        up=1;
    if(up==1)
    {
       pix_up.load(":/new/prefix1/上1.png");
       this->setPixmap(pix_up);
       this->move(this->x(),this->y()-speed);
       up++;
    }
    else if(up == 2)
    {
        pix_left.load(":/new/prefix1/上2.png");
        this->setPixmap(pix_up);
        this->move(this->x(),this->y()-speed);
        up++;
    }
    else if(up == 3)
    {
        pix_up.load(":/new/prefix1/上3.png");
        this->setPixmap(pix_up);
        this->move(this->x(),this->y()-speed);
        up++;
    }
}
void Man::DownMove()
{
    if(down == 3)
        down=1;
    if(down==1)
    {
       pix_down.load(":/new/prefix1/下1.png");
       this->setPixmap(pix_down);
       this->move(this->x(),this->y()+speed);
       down++;
    }
    else if(down == 2)
    {
        pix_down.load(":/new/prefix1/下2.png");
        this->setPixmap(pix_down);
        this->move(this->x(),this->y()+speed);
        down++;
    }

}
void Man::Dead()
{
    movie->stop();
    movie->setFileName(":/new/prefix1/素材/死亡.gif");
    movie->start();
}

void Man::Stop()
{

}
