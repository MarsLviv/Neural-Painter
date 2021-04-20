#ifndef MIRRORCONVERTER_H
#define MIRRORCONVERTER_H

#include "imageconverter.h"

class MirrorConverter : public ImageConverter
{
public:
    MirrorConverter(QObject *parentt = nullptr);
    virtual ~MirrorConverter();

    virtual QString convert(QImage *) override;
    virtual QString name() override;
    virtual Conversions itemValue() override;    // for Combobox
public:
    const QString conversionName = "Mirror";

};

#endif // MIRRORCONVERTER_H
