#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "../Widgets/mainwindow.h"

class ImageConverter;
class ImageConverterInfo;

enum class Conversions {MIRROR, GRAYSCALE, COLORIZATION, GOOGLE_DEEP_DREAM};

class Controller : QObject
{
    Q_OBJECT

public:
    Controller(MainWindow *mainWindow);
    ~Controller();

    QVector<ImageConverterInfo *> getConversionInfo() const;

private:
    ImageConverter * makeConverter(Conversions);
    ImageConverterInfo * makeConverterInfo(QString name, Conversions conversion);
private:
    QImage * inputImage {nullptr};
    QImage * outputImage {nullptr};

    MainWindow * mainWindow {nullptr};

    ImageConverter * imageConverter {nullptr};

    QVector<ImageConverterInfo *> imageConverterInfo;
};

#endif // CONTROLLER_H
