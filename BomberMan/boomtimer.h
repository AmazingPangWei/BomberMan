#ifndef BOOMTIMER_H
#define BOOMTIMER_H

#include <QLabel>
#include <QPixmap>
class BoomTimer : public QLabel
{
    Q_OBJECT
public:
    explicit BoomTimer(QWidget *parent = 0);
signals:

public slots:

private:
    QPixmap pix;

};

#endif // BOOMTIMER_H
