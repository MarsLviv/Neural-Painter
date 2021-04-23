#ifndef MIRRORCONVERTER_H
#define MIRRORCONVERTER_H

#include "imageconverter.h"

class MirrorConverter : public ImageConverter
{
public:
    MirrorConverter(QObject *parentt = nullptr);
    virtual ~MirrorConverter() = default;

    QString convert(QImage *) override;

public:
    const QString conversionName = "Mirror";

};

#endif // MIRRORCONVERTER_H
