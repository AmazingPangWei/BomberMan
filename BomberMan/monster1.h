#ifndef MONSTER1_H
#define MONSTER1_H

#include "monster.h"
#include <QTimer>
class Monster1 : public Monster
{
    Q_OBJECT
signals:

public slots:
    void clear();
public:
    explicit Monster1(QWidget *parent = 0);
    void RightMove();
    void LeftMove();
    void UpMove();
    void DownMove();
    void Dead();
    QTimer *timer;
};

#endif // MONSTER1_H
