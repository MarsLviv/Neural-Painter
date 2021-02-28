#ifndef WGTDROPDOWNFEATURES_H
#define WGTDROPDOWNFEATURES_H

#include<QWidget>

class QLabel;
class QHBoxLayout;
class QComboBox;

class WgtDropDownFeatures : public QWidget
{
    Q_OBJECT

    QHBoxLayout * mainLayout {nullptr};

    QLabel * title {nullptr};
    QComboBox * dropDownFeatures {nullptr};

public:
    WgtDropDownFeatures(QWidget *parent = nullptr);
};

#endif // WGTDROPDOWNFEATURES_H
