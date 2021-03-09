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

    w.setWindowTitle("Painter v 0.1");                              // TODO: move to separate file

    // run thread_1 to load Networks
    // run thread_2 to hanle Conversion

    // make Controller object and run it in separate thread_3 (handle user activity - Buttons, Dropdown menu)

    w.show();

    // thread_1.join()
    // thread_2.join()
    // thread_3.join()

    return a.exec(); // not reach this expression
}
