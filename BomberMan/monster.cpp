#include "monster.h"

Monster::Monster(QWidget *parent):QLabel(parent)
{
    running = 0;
    count = 0;
    fang = 0;
    islive = 1;
}

