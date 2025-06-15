#include "widget.h"
#include "denglu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    denglu deng;
    deng.show();


    return a.exec();
}
