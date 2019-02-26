#ifndef MEADOW_H
#define MEADOW_H

#include <QWidget>
#include "boom.h"
#include "man.h"
#include "Wall.h"
#include "fewall.h"
#include "monster1.h"
#include "mythread.h"
#include "boomtimer.h"
#include "boomup.h"
#include "powerup.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QStyleOption>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <QList>
#define MAX_X 33
#define MAX_Y 15
#define MAX_guai 10
class Meadow : public QWidget
{
    Q_OBJECT
public:
    explicit Meadow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void drawBackGround();
    void running();     //所有怪物运动
    int status[MAX_X][MAX_Y]; //记录各个地方的状态 0：空地； 1：障碍物；2: 砖块墙 、、、
    int GetWall[MAX_X][MAX_Y];
    int x, y;           //暂时代替小怪
    int fang; //加到小怪里面去
    void StartGame();
    QTimer *countTimer;
    double toalCore;
    double toalTime;
    void StopGame();
    void DrawMan();
    void DrawFeWall();        //画出不可炸的铁墙
    void DrawWall();
    void DrawMonster1();
    int ismove(int x, int y); //判断是否可以移动
    void DrawBomb();  //炸弹必须提前new好，不可能编译运行后掉函数去new一个！！！
    void DrawTool();  //写出道具,并隐藏
    void GetTool();   //人获得道具
    int isCollide(int x1, int y, int x2, int y2);
    QLabel *labels[MAX_X][MAX_Y];
    Wall *mywall[400];       //砖墙
    Monster1 *monster1[20];  //小怪
    MyThread myThread;
    Boom *bomb[5];         //炸弹
    Man *man;
private:
//MyThread thread;
//    Man *man;
//    Man *man2;
    QPixmap pix;
    QLabel *t;
    QMovie *movie;
    int Press;
    BoomUp *BoomUpCard[10];  //拥有炸弹数量增加卡
    BoomTimer *timer[10];    //定时炸弹卡
    PowerUp *powerup[10];    //威力加强卡

    struct order
    {
        int index;
        int i;
        int j;
    };
    QList<order> list;//用于存炸弹的顺序
    int IfBoom;//判断是否是强制引爆的
    int flag;    //用于判断是否有了定时器

    QPixmap pix_up,pix_down,pix_left,pix_right;

signals:

public slots:
    void MonsterRunning(int i);  //小怪运动
    void BoomOver();
    void slotsOpenFire(int ,int);
    void slotsStopFire(int ,int);
    void countTime();
    void BoomOver1();
};

#endif // MEADOW_H

