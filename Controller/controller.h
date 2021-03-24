#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : QObject
{
    Q_OBJECT

public:
    Controller(QObject *parentt = nullptr);
};

#endif // CONTROLLER_H
