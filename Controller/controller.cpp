#include "controller.h"

Controller::Controller(QImage *inputImage, QImage *outputImage, QString conversion, QObject *parent)
    : QObject(parent)
    , inputImage(inputImage)
    , outputImage(outputImage)
    , conversion(conversion)
{

}
