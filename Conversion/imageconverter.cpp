#include "imageconverter.h"

ImageConverter::ImageConverter(QObject *parent) : QObject(parent)
{

}

QString ImageConverter::name()
{
    return imageConverterInfo->name();
}

Conversions ImageConverter::itemValue()
{
    return imageConverterInfo->itemValue();
}

ImageConverterInfo::ImageConverterInfo(QString name, Conversions conversions) : _name(name), _itemValue(conversions)
{

}

QString ImageConverterInfo::name()
{
    return _name;
}

Conversions ImageConverterInfo::itemValue()
{
    return _itemValue;
}
