#ifndef UTILSPICTURE_H
#define UTILSPICTURE_H

#include<QDebug>
#include<QDateTime>
#include<QDirIterator>

namespace Utils {
    inline QString randomPictureName()
    {
        QStringList files;
        QDirIterator it(":", QDirIterator::Subdirectories);
        while (it.hasNext()) {
            auto file = it.next();
            if (file.indexOf(".jpg") != -1)
                files.append(file);
        }

        auto secondsEpoch = QDateTime::currentSecsSinceEpoch();
        auto fileNumberToShow {secondsEpoch % files.length()};

        return files[fileNumberToShow];
    };
}


#endif // UTILSPICTURE_H
