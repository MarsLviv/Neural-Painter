#ifndef UTILSPICTURE_H
#define UTILSPICTURE_H

#include<QDebug>
#include<QDateTime>
#include <QFile>

namespace Utils {
    int randomPictureName()
    {
        QFile resouceFile("../paints.qrc");// path to src directory, but in runtime exe file in destination dir -> todo it in compile time -> constexpr can't have non-literal type

        if (!resouceFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return 0;
        QStringList files;

        QTextStream inStream(&resouceFile);
        while (!inStream.atEnd()) {
            QString line = inStream.readLine();
            qDebug() << "line" << line;
        }


        auto secondsEpoch = QDateTime::currentSecsSinceEpoch();
        qDebug() << "secondsEpoch:" << secondsEpoch % 5;

        resouceFile.close();
        return secondsEpoch % 5;
    };
}


#endif // UTILSPICTURE_H
