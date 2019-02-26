#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    num=1;
    timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_GameOver()));
    player = new QMediaPlayer;
    list =new QMediaPlaylist;
    list->addMedia(QUrl::fromLocalFile("C:/Users/18323/Desktop/study/Qt_test/boom/BGM/群星 - FC《马戏团》第1、4关BGM.mp3"));
    list->addMedia(QUrl::fromLocalFile("C:/Users/18323/Desktop/study/Qt_test/boom/BGM/V.A. - BGM2.mp3"));
    list->addMedia(QUrl::fromLocalFile("C:/Users/18323/Desktop/study/Qt_test/boom/BGM/群星 - FC《魂斗罗》Base.mp3"));
    list->addMedia(QUrl::fromLocalFile("C:/Users/18323/Desktop/study/Qt_test/boom/BGM/門倉聡 - WANTED!.mp3"));
    list->setCurrentIndex(0);
    list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(list);
    player->setVolume(50);
    player->play();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::slot_GameOver(){
    if(ui->widget_3->man->IsLive() == 0 || ui->widget_3->toalTime >= 200 || ui->widget_3->toalCore >= 1000){
        ui->stackedWidget->setCurrentIndex(2);
//        ui->widget_3->myThread.stop();
        ui->widget_3->StopGame();
        timer->stop();
        ui->label_5->setText(QString(" %1").arg(ui->widget_3->toalTime - 0.5));
        ui->label_7->setText(QString(" %1").arg(ui->widget_3->toalCore));
    }
    ui->label_15->setText(QString("Time: %1s").arg(200 - (int)ui->widget_3->toalTime ));
}
void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->widget_3->StartGame();
}

void Widget::on_pushButton_4_clicked()
{
    ui->widget_3->StopGame();
}

void Widget::on_pushButton_5_clicked()
{
    int currentIndex=list->currentIndex();
    if(currentIndex == 0)
        currentIndex=3;
    else
        currentIndex--;
    list->setCurrentIndex(currentIndex);
    player->play();
}
void Widget::on_pushButton_7_clicked()
{
    int currentIndex=list->currentIndex();
    if(currentIndex == 3)
        currentIndex=0;
    else
        currentIndex++;
    list->setCurrentIndex(currentIndex);
    player->play();
}

void Widget::on_pushButton_6_clicked()
{
    switch (player->state())
    {
        case QMediaPlayer::PlayingState:
            player->pause();
            break;
        default:
            player->play();
            break;
     }
}

void Widget::on_pushButton_3_clicked()
{
    timer->stop();
    ui->widget_3->myThread.stop();
    this->close();
//    QApplication::exit();  //关闭游戏
}
