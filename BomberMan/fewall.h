#ifndef FEWALL_H
#define FEWALL_H

#include <QLabel>
#include <QPixmap>
class FeWall : public QLabel
{
    Q_OBJECT
public:
    explicit FeWall(QWidget *parent = 0);

private:
    QPixmap pix;
};

#endif // FEWALL_H


