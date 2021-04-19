#include "mirrorconverter.h"

#include <QDateTime>
#include <QImage>
#include <QDir>

MirrorConverter::MirrorConverter(QObject *parent) : ImageConverter(parent)
{

}

MirrorConverter::~MirrorConverter()
{

}

QString MirrorConverter::Convert(QImage * image)
{
    auto secondsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    QString fileName = conversionName + QString::number(secondsSinceEpoch) + ".jpg";
    auto tempPath = QDir::tempPath() + QDir::separator() + fileName;
    image->mirrored(true, false).save(tempPath);

    return tempPath;
}
