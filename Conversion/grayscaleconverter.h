#ifndef GRAYSCALECONVERTER_H
#define GRAYSCALECONVERTER_H

#include "imageconverter.h"

class GrayscaleConverter : public ImageConverter
{
public:
    GrayscaleConverter(QObject *parentt = nullptr);
    /*virtual*/ ~GrayscaleConverter();

    /*virtual*/ QString Convert(QImage *);

    QString simpleClassName = "GrayscaleConverter";
    QString conversionName = "grayscale";
};

#endif // GRAYSCALECONVERTER_H
