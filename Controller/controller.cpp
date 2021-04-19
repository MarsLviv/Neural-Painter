#include "controller.h"

#include <QDir>
#include <QImage>

#include "Conversion/mirrorconverter.h"
#include "Conversion/grayscaleconverter.h"

Controller::Controller(MainWindow *mainWindow, QObject *parent)
    : QObject(parent)
    , mainWindow(mainWindow)
{
    imageConverter = new MirrorConverter;
    auto convertedImagePath = imageConverter->Convert(mainWindow->getInputImage());
    mainWindow->setOutputImage(convertedImagePath);

//    imageConverter = new GrayscaleConverter;
//    convertedImagePath = imageConverter->Convert(mainWindow->getInputImage());
//    mainWindow->setOutputImage(convertedImagePath);
}
