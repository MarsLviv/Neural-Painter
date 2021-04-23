#include "imageconverter.h"

ImageConverter::ImageConverter(QObject *parent) : QObject(parent)
{

}

QString ImageConverter::name() const
{
    return imageConverterInfo->name();
}

Conversions ImageConverter::itemValue() const
{
    return imageConverterInfo->itemValue();
}

ImageConverterInfo::ImageConverterInfo(QString name, Conversions conversion) : _name(name), _itemValue(conversion)
{

}

QString ImageConverterInfo::name() const
{
    return _name;
}

Conversions ImageConverterInfo::itemValue() const
{
    return _itemValue;
}
