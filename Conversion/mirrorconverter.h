#ifndef MIRRORCONVERTER_H
#define MIRRORCONVERTER_H

#include "imageconverter.h"

class MirrorConverter : public ImageConverter
{
public:
    MirrorConverter(QObject *parentt = nullptr);
    /*virtual*/ ~MirrorConverter();

    /*virtual*/ QString Convert(QImage *);

    QString simpleClassName = "MirrorConverter";
    QString conversionName = "mirror";
};

#endif // MIRRORCONVERTER_H
