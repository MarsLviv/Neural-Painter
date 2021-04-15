#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : QObject
{
    Q_OBJECT

public:
    Controller(QImage *inputImage, QImage *outputImage, QString conversion, QObject *parent = nullptr);
private:
    QImage *inputImage {nullptr};
    QImage *outputImage {nullptr};

    QString conversion;
};

#endif // CONTROLLER_H
