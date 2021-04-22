#include "grayscaleconverter.h"
#include "Controller/controller.h"

#include <QDateTime>
#include <QImage>
#include <QDir>

GrayscaleConverter::GrayscaleConverter(QObject *parent) : ImageConverter(parent)
{

}

QString GrayscaleConverter::convert(QImage *image)
{
    auto secondsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    QString fileName = conversionName.simplified().remove(' ') + QString::number(secondsSinceEpoch) + ".jpg";
    auto tempPath = QDir::tempPath() + QDir::separator() + fileName;
    image->convertToFormat(QImage::Format_Grayscale8).save(tempPath);

    return tempPath;
}
