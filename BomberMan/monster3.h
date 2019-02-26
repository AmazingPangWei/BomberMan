#ifndef MONSTER3_H
#define MONSTER3_H
#include "monster.h"
class Monster3 : public Monster
{
    Q_OBJECT
signals:

public slots:

public:
    explicit Monster3(QWidget *parent = 0);
    void RightMove();
    void LeftMove();
    void UpMove();
    void DownMove();
    void Dead();
};
#endif // MONSTER3_H
