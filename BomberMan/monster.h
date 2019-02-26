#ifndef MONSTER_H
#define MONSTER_H

#include <QLabel>
#include <QMovie>
#include <QPixmap>
class Monster : public QLabel
{
    Q_OBJECT
signals:

public slots:

public:
    explicit Monster(QWidget *parent = 0);
    void RightMove();
    void LeftMove();
    void UpMove();
    void DownMove();
    void Dead();
    int count;
    int running;
    int fang;
    bool islive;
protected:
    int speed;
    QMovie *movie;
    QPixmap pix;
};

#endif // MONSTER_H
