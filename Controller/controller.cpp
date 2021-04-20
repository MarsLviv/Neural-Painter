#include "controller.h"

#include <QDir>
#include <QImage>

#include "Conversion/mirrorconverter.h"
#include "Conversion/grayscaleconverter.h"

Controller::Controller(MainWindow *mainWindow)
    : QObject(nullptr)
    , mainWindow(mainWindow)
{
    conversionInstances.append(makeConverter(Conversions::MIRROR));
    conversionInstances.append(makeConverter(Conversions::GRAYSCALE));

    imageConverter = conversionInstances[0];
    auto convertedImagePath = imageConverter->convert(mainWindow->getInputImage());
    mainWindow->setOutputImage(convertedImagePath);

    mainWindow->deliverController(this);
}

Controller::~Controller()
{
    for(auto conversionInstance: conversionInstances)
        delete conversionInstance;
}

ImageConverter *Controller::makeConverter(Conversions conversions)
{
    switch (conversions) {
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

QVector<ImageConverter *> Controller::getConversionInstances() const
{
    return conversionInstances;
}

