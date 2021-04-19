#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include<QObject>

class ImageConverter : public QObject
{
    Q_OBJECT

public:
    ImageConverter(QObject *parentt = nullptr);
    virtual ~ImageConverter();

    virtual QString Convert(QImage *) = 0;

};

#endif // IMAGECONVERTER_H
