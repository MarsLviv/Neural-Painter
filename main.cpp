#include <QApplication>
#include <QScreen>

#include "UI/mainwindow.h"
#include "Utils/applocation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Utils::AppLocation::calculateAppGeometry();
    w.move(Utils::AppLocation::appMoveOnX, Utils::AppLocation::appMoveOnY);       // move App to screen center
    w.setMinimumWidth(Utils::AppLocation::appMinWidth);
    w.setMinimumHeight(Utils::AppLocation::appMinHeight);

    w.setWindowTitle("Painter v 0.1");                              // TODO: move to settings

    w.show();
    return a.exec();
}
