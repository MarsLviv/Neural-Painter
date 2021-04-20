#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "../Widgets/mainwindow.h"
//#include "../Conversion/imageconverter.h"

class ImageConverter;

enum class Conversions {MIRROR, GRAYSCALE, COLORIZATION, GOOGLE_DEEP_DREAM};

class Controller : QObject
{
    Q_OBJECT

public:
    Controller(MainWindow *mainWindow);
    ~Controller();

    QVector<ImageConverter *> getConversionInstances() const;

private:
    ImageConverter * makeConverter(Conversions);

private:

    QImage * inputImage {nullptr};
    QImage * outputImage {nullptr};

    QString conversion;

    MainWindow * mainWindow {nullptr};

    ImageConverter * imageConverter {nullptr};

    QVector<ImageConverter *> conversionInstances;
};

#endif // CONTROLLER_H
