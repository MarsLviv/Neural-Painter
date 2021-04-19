#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "../Widgets/mainwindow.h"
#include "../Conversion/imageconverter.h"

class Controller : QObject
{
    Q_OBJECT

public:
    Controller(MainWindow *mainWindow, QObject *parent = nullptr);
private:
    QImage * inputImage {nullptr};
    QImage * outputImage {nullptr};

    QString conversion;

    MainWindow * mainWindow {nullptr};

    ImageConverter * imageConverter {nullptr};
};

#endif // CONTROLLER_H
