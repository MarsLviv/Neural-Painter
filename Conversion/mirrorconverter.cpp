#include "mirrorconverter.h"
#include "Controller/controller.h"

#include <QDateTime>
#include <QImage>
#include <QDir>

MirrorConverter::MirrorConverter(QObject *parent) : ImageConverter(parent)
{

}

MirrorConverter::~MirrorConverter()
{

}

QString MirrorConverter::convert(QImage * image)
{
    auto secondsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    QString fileName = conversionName.simplified().remove(' ') + QString::number(secondsSinceEpoch) + ".jpg";
    auto tempPath = QDir::tempPath() + QDir::separator() + fileName;
    image->mirrored(true, false).save(tempPath);

    return tempPath;
}

QString MirrorConverter::name()
{
    return conversionName;
}

Conversions MirrorConverter::itemValue()
{
    return Conversions::MIRROR;
}
