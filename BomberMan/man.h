#ifndef MAN_H
#define MAN_H

#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QMovie>
#include <QDebug>
#include <QTimer>
class Man:public QLabel
{
    Q_OBJECT
signals:

public slots:
    void printf();

private:
    QTimer *timer;
    int speed;
    int BoomNum;
    int power;
    bool IsTimer;
    bool IsCrossWall;
    int isLive;  //人的生命值

    int left;
    int right;
    int up;
    int down;

    QMovie *movie;
    QPixmap pix_up;
    QPixmap pix_down;
    QPixmap pix_right;
    QPixmap pix_left;
public:
    explicit Man(QWidget *parent = 0);
    int CountBomb;
    int GetSpeed();
    int GetBoomNum();
    int GetPower();
    void SetSpeed(int speed);
    void SetBoomNum(int BoomNum);
    void PowerUp();
    void SpeedUp();
    void BoomNumUp();
    void SetBoom(); //放炸弹
    void RightMove();
    void LeftMove();
    void UpMove();
    void DownMove();
    void Dead();
    void Stop();
    int IsLive();
};

#endif // MAN_H
