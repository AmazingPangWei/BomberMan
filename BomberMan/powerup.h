#ifndef POWERUP_H
#define POWERUP_H

#include <QLabel>
#include <QPixmap>
class PowerUp : public QLabel
{
    Q_OBJECT
public:
    explicit PowerUp(QWidget *parent = 0);
signals:

public slots:

private:
    QPixmap pix;
};

#endif // POWERUP_H
