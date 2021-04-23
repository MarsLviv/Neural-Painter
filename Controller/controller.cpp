#include "controller.h"
#include "Conversion/mirrorconverter.h"
#include "Conversion/grayscaleconverter.h"

#include <QDir>
#include <QImage>

Controller::Controller() : QObject(nullptr)
{
    imageConverterInfo.append(makeConverterInfo("Mirror", Conversions::MIRROR));
    imageConverterInfo.append(makeConverterInfo("Grayscale", Conversions::GRAYSCALE));

    imageConverter = makeConverter(Conversions::MIRROR);
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

ImageConverterInfo * Controller::makeConverterInfo(QString name, Conversions conversion)
{
    return new ImageConverterInfo(name, conversion);
}

QVector<ImageConverterInfo *> Controller::getConversionInfo() const
{
    return imageConverterInfo;
}

ImageConverter * Controller::getConversion() const
{
    return imageConverter;
}

