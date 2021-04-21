#include "controller.h"

#include <QDir>
#include <QImage>

#include "Conversion/mirrorconverter.h"
#include "Conversion/grayscaleconverter.h"

Controller::Controller(MainWindow *mainWindow)
    : QObject(nullptr)
    , mainWindow(mainWindow)
{
    imageConverterInfo.append(makeConverterInfo("Mirror", Conversions::MIRROR));
    imageConverterInfo.append(makeConverterInfo("Grayscale", Conversions::GRAYSCALE));

    imageConverter = makeConverter(Conversions::MIRROR);
    auto convertedImagePath = imageConverter->convert(mainWindow->getInputImage());
    mainWindow->setOutputImage(convertedImagePath);

    mainWindow->deliverController(this);
}

Controller::~Controller()
{
    for(auto _imageConverterInfo: imageConverterInfo)
        delete _imageConverterInfo;

    delete imageConverter;
}

ImageConverter * Controller::makeConverter(Conversions conversion)
{
    switch (conversion) {
    case Conversions::MIRROR:
        return new MirrorConverter;
    case Conversions::GRAYSCALE:
        return new GrayscaleConverter;
    case Conversions::COLORIZATION:
        return nullptr;
    case Conversions::GOOGLE_DEEP_DREAM:
        return nullptr;
    }
}

ImageConverterInfo * Controller::makeConverterInfo(QString name, Conversions conversions)
{
    return new ImageConverterInfo(name, conversions);
}

QVector<ImageConverterInfo *> Controller::getConversionInfo() const
{
    return imageConverterInfo;
}

