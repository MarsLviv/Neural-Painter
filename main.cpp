#include <QApplication>
#include <QScreen>

#include "Widgets/mainwindow.h"
#include "Utils/applocation.h"
#include "Utils/utilspicture.h"
#include "Helpers/constants.h"
#include <Controller/controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Utils::AppLocation::calculateAppGeometry();
    w.move(Utils::AppLocation::appMoveOnX, Utils::AppLocation::appMoveOnY);       // move App to screen center
    w.setMinimumWidth(Utils::AppLocation::appMinWidth);
    w.setMinimumHeight(Utils::AppLocation::appMinHeight);

    w.setWindowTitle(Helpers::appName);

    // run thread_1 to load Networks
    // run thread_2 to hanle Conversion

    // make Controller object and run it in separate thread_3 (handle user activity - Buttons, Dropdown menu)
    Controller controller;

    w.show();
    // test setImage getImage methods
//    auto pictureFile = Utils::randomPictureName();
//    pictureFile = ":/LvivLarge1.jpg";
//    pictureFile = ":/Lviv1.jpg";
//    w.setInputImage(pictureFile);
//    pictureFile = ":/Lviv3.jpg";
//    w.setOutputImage(pictureFile);
    // </> test setImage getImage methods

    QString fileName = "mirrored.jpg";
    auto tempPath = QDir::tempPath() + QDir::separator() + fileName;

    QImage *im = w.getInputImage();
    QImage im_mirrored = im->mirrored(true, false);
    im_mirrored.save(tempPath);
    w.setOutputImage(tempPath);

    // thread_1.join()
    // thread_2.join()
    // thread_3.join()

    return a.exec(); // not reach this expression
}
