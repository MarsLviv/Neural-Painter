#ifndef WGTINPUTIMAGE_H
#define WGTINPUTIMAGE_H

#include<QScrollArea>

class Controller;

class ImageConverterInfo;

class QVBoxLayout;
class QPushButton;
class QLabel;

class WgtImage;
class WgtDropDownFeatures;
enum class Conversions;

class WgtInputImage : public QScrollArea
{
    Q_OBJECT
public:
    WgtInputImage(QWidget *parent);

    void setImage(QString &fileName);
    QImage * getImage();

    QString conversion() const;
    //void deliverController(Controller *);
    void setController(Controller *controller);
    void addItemToCombobox(ImageConverterInfo *imageConverterInfo);

private:
    void makeConversion(Conversions conversion);

private slots:
        void onConvertButtonClick();

private:
    QVBoxLayout * mainLayout {nullptr};

    QLabel * inputImageTitle {nullptr};
    WgtImage * inputImage {nullptr};
    WgtDropDownFeatures * wgtDropDownFeatures {nullptr};
    QPushButton * convertBtn {nullptr};

    Controller * controller {nullptr};

};

#endif // WGTINPUTIMAGE_H
