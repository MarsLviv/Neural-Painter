#ifndef WGTDROPDOWNFEATURES_H
#define WGTDROPDOWNFEATURES_H

#include<QWidget>

class ImageConverter;
class ImageConverterInfo;
class Controller;

class QLabel;
class QHBoxLayout;
class QComboBox;

class WgtDropDownFeatures : public QWidget
{
    Q_OBJECT

public:
    WgtDropDownFeatures(QWidget *parent = nullptr);

    QString conversion() const;
    int conversionIndex() const;

    void addItemToCombobox(ImageConverterInfo *imageConverterInfo);
    //void deliverController(Controller *);
private:
    QHBoxLayout * mainLayout {nullptr};

    QLabel * title {nullptr};
    QComboBox * dropDownFeatures {nullptr};
};

#endif // WGTDROPDOWNFEATURES_H
