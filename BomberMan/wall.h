#ifndef WALL_H
#define WALL_H

#include <QLabel>
#include <QPixmap>
class Wall : public QLabel
{
    Q_OBJECT
public:
    explicit Wall(QWidget *parent = 0);
    void Dead();
    void CreatWall();
signals:

public slots:

private:
    QPixmap pix;
};

#endif // WALL_H
