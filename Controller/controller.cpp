#include "controller.h"

#include <QDir>
#include <QImage>

Controller::Controller(MainWindow *mainWindow, QObject *parent)
    : QObject(parent)
    , mainWindow(mainWindow)
{
    // implement default conversion
    QString fileName = "mirrored.jpg";
    auto tempPath = QDir::tempPath() + QDir::separator() + fileName;

    QImage *im = mainWindow->getInputImage();
    QImage im_mirrored = im->mirrored(true, false);
    im_mirrored.save(tempPath);
    mainWindow->setOutputImage(tempPath);
    // </> implement default conversion
}
