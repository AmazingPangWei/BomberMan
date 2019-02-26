#include "boom.h"

Boom::Boom(QWidget *parent):QLabel(parent)
{
    player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/18323/Desktop/study/Qt_test/boom/素材/炸弹爆炸.mp3"));
    player->setVolume(50);
    flag=1;
    flag1=1;
    movie =  new QMovie(":/new/prefix1/素材/炸弹.gif");
    pix.load(":/new/prefix1/素材/炸弹中心.png");
    timer = new QTimer(this);
    this->setMovie(movie);
    movie->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(StartBoom()));
//    pix.load(":/new/prefix1/素材/炸弹2.png");
//    this->setPixmap(pix);
}
void Boom::start(int (&state)[33][15],int x,int y){  //开始计时
    this->show();
    this->setMovie(movie);
    movie->start();
    countTime=0;
    state[x][y]=3;
    if(flag)
     timer->start(100);
}
void Boom::StartBoom(){
    countTime += 0.1;
    if(countTime >= 2.5){  //小于2.5秒时在等待爆炸
//        timer->stop();
//        pix.load(":/new/prefix1/素材/第三关怪物.png");
//        this->setPixmap(pix);
          player->play();
          movie->stop();
    //    this->setMovie(bombmovie);
        this->setPixmap(pix);
        if(countTime < 3){
            int i = (this->x()) / 35;
            int j = (this->y()) / 35;
            emit OpenFire(i,j); //显示炸弹范围及效果1秒，传出炸弹的坐标
        }
        if(countTime >= 3){   //结束爆炸效果
      //      this->clear();
            this->hide();
            timer->stop();
            int i = (this->x()) / 35;   //炸弹放在人中心点所在的格子
            int j = (this->y()) / 35;
            emit StopFire(i,j);
            if(flag1)
            {
                  emit over();        //爆炸结束
            }
            else
            {
                emit over1();
                flag1=1;
            }
//            this->hide();       //炸弹消失
        }

    }
}
void Boom::fire(){    //定时引爆  //考虑一下，引爆对应哪一个炸弹，
    timer->start(100);
    countTime = 2.5;
//    pix.load(":/new/prefix1/素材/第三关怪物.png");
//    this->setPixmap(pix);
}
void Boom::fire1()
{
    fire();
    flag1=0;
}

void Boom::GetTimer()
{
    timer->stop();
    flag=0;
}

