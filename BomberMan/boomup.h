#ifndef BOOMUP_H
#define BOOMUP_H

#include <QLabel>
#include <QPixmap>
class BoomUp : public QLabel
{
    Q_OBJECT
public:
    explicit BoomUp(QWidget *parent = 0);
signals:

public slots:

private:
    QPixmap pix;

};

#endif // BOOMUP_H
