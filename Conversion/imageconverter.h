#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include<QObject>


class ImageConverter : QObject
{
    Q_OBJECT

public:
    ImageConverter(QObject *parentt = nullptr);
    virtual ~ImageConverter();

    virtual void Convert(QImage &);
};

#endif // IMAGECONVERTER_H
