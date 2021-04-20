#ifndef GRAYSCALECONVERTER_H
#define GRAYSCALECONVERTER_H

#include "imageconverter.h"

class GrayscaleConverter : public ImageConverter
{
public:
    GrayscaleConverter(QObject *parentt = nullptr);
    virtual ~GrayscaleConverter();

    virtual QString convert(QImage *) override;
    virtual QString name() override;
    virtual Conversions itemValue() override;    // for Combobox
public:
    const QString conversionName = "Grayscale";
};

#endif // GRAYSCALECONVERTER_H
