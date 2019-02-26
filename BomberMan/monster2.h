#ifndef MONSTER2_H
#define MONSTER2_H
#include "monster.h"

class Monster2 : public Monster
{
    Q_OBJECT
signals:

public slots:

public:
    explicit Monster2(QWidget *parent = 0);
    void RightMove();
    void LeftMove();
    void UpMove();
    void DownMove();
    void Dead();
};

#endif // MONSTER2_H
