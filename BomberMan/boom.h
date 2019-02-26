#ifndef BOOM_H
#define BOOM_H
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QMovie>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
class Boom : public QLabel
{
    Q_OBJECT
signals:
    void OpenFire(int x,int y);
    void StopFire(int x,int y);
    void over();
    void over1();//被强制引爆的
public slots:
    void StartBoom();
public:
    explicit Boom(QWidget *parent = 0);
    void GetTimer();
    QPixmap pix;
    QTimer *timer;
    QMovie *movie;
    void start(int (&state)[33][15] , int x,int y);
    void fire();
    void fire1();
    int flag1;
    int flag;
    double countTime;
    QMediaPlayer *player;
};

#endif // BOOM_H
