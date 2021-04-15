#ifndef WGTINPUTIMAGE_H
#define WGTINPUTIMAGE_H

#include<QScrollArea>

class QVBoxLayout;
class QPushButton;
class QLabel;

class WgtImage;
class WgtDropDownFeatures;

class WgtInputImage : public QScrollArea
{
    Q_OBJECT
public:
    WgtInputImage(QWidget *parent);

    void setImage(QString &fileName);
    QImage * getImage();

    QString conversion() const;
private:
    QVBoxLayout * mainLayout {nullptr};

    QLabel * inputImageTitle {nullptr};
    WgtImage * inputImage {nullptr};
    WgtDropDownFeatures * wgtDropDownFeatures {nullptr};
    QPushButton * convertBtn {nullptr};
};

#endif // WGTINPUTIMAGE_H
