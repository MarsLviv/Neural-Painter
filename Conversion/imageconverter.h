#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include "Controller/controller.h"

#include<QObject>

//enum class Conversions;

class ImageConverter : public QObject
{
    Q_OBJECT

public:
    ImageConverter(QObject *parentt = nullptr);
    virtual ~ImageConverter();

    virtual QString convert(QImage *) = 0;
    virtual QString name() = 0;
    virtual Conversions itemValue() = 0;    // for Combobox
};

#endif // IMAGECONVERTER_H
