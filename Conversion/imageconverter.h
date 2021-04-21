#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include "Controller/controller.h"

#include<QObject>

class ImageConverterInfo;

class ImageConverter : public QObject
{
    Q_OBJECT

public:
    ImageConverter(QObject *parentt = nullptr);
    virtual ~ImageConverter() = default;

    virtual QString convert(QImage *) = 0;

    QString name();
    Conversions itemValue();    // for Combobox

    ImageConverterInfo *imageConverterInfo;
};

class ImageConverterInfo
{
public:
    ImageConverterInfo(QString name, Conversions conversion);

    QString name();
    Conversions itemValue();    // for Combobox
private:
    QString _name;
    Conversions _itemValue;
};

#endif // IMAGECONVERTER_H
