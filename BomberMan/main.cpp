#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize( w.width (),w.height ());
    w.setWindowTitle("炸弹人");
    w.show();

    return a.exec();
}
