#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class ImageConverter;
class ImageConverterInfo;

enum class Conversions {MIRROR, GRAYSCALE, COLORIZATION, GOOGLE_DEEP_DREAM};

class Controller : QObject
{
    Q_OBJECT

public:
    Controller();
    ~Controller();

    QVector<ImageConverterInfo *> getConversionInfo() const;

    ImageConverter * getConversion() const;
    ImageConverter * makeConverter(Conversions);

private:
    ImageConverterInfo * makeConverterInfo(QString name, Conversions conversion);

private:
    ImageConverter *imageConverter {nullptr};

    QVector<ImageConverterInfo *> imageConverterInfo;
};

#endif // CONTROLLER_H
