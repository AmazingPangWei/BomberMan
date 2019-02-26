#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlaylist>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void slot_GameOver();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QMediaPlayer *player;
    QMediaPlaylist *list;
    QTimer *timer;
    int num;//控制音乐播放与暂停
};

#endif // WIDGET_H
