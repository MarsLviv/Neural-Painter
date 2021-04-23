#ifndef GRAYSCALECONVERTER_H
#define GRAYSCALECONVERTER_H

#include "imageconverter.h"

class GrayscaleConverter : public ImageConverter
{
public:
    GrayscaleConverter(QObject *parentt = nullptr);
    virtual ~GrayscaleConverter() = default;

    QString convert(QImage *) override;

public:
    const QString conversionName = "Grayscale";
};

#endif // GRAYSCALECONVERTER_H
