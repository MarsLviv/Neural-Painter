#ifndef WGTINPUTIMAGE_H
#define WGTINPUTIMAGE_H

#include<QScrollArea>

class QVBoxLayout;
class QLabel;
class QPushButton;

class WgtImage;
class WgtDropDownFeatures;

class WgtInputImage : public QScrollArea
{
    Q_OBJECT
public:
    WgtInputImage(QWidget *parent);


private:
    QVBoxLayout * mainLayout {nullptr};

    QLabel * inputImageTitle {nullptr};
    WgtImage * inputImage {nullptr};
    WgtDropDownFeatures * wgtDropDownFeatures {nullptr};
    QPushButton * convertBtn {nullptr};


};

#endif // WGTINPUTIMAGE_H
