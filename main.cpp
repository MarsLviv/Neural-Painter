#include "mainwindow.h"

#include <QApplication>
//#include <QtWidgets>
#include <QScreen>

#include "applocation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    AppLocation::calculateAppGeometry();
    w.move(AppLocation::appMoveOnX, AppLocation::appMoveOnY);       // move App to screen center
    w.setMinimumWidth(AppLocation::appMinWidth);
    w.setMinimumHeight(AppLocation::appMinHeight);

    w.setWindowTitle("Painter v 0.1");                              // TODO: move to settings

    // add logging
    // add settings


    w.show();
    return a.exec();
}
