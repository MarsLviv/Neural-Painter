#include "grayscaleconverter.h"

#include <QDateTime>
#include <QImage>
#include <QDir>

GrayscaleConverter::GrayscaleConverter(QObject *parent) : ImageConverter(parent)
{

}

GrayscaleConverter::~GrayscaleConverter()
{

}

QString GrayscaleConverter::Convert(QImage *image)
{
    auto secondsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    QString fileName = conversionName + QString::number(secondsSinceEpoch) + ".jpg";
    auto tempPath = QDir::tempPath() + QDir::separator() + fileName;
    image->convertToFormat(QImage::Format_Grayscale8).save(tempPath);

    return tempPath;

}
