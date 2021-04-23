#ifndef WGTINPUTIMAGE_H
#define WGTINPUTIMAGE_H

#include<QScrollArea>

class WgtImage;
class Controller;
class ImageConverterInfo;
class WgtDropDownFeatures;
enum class Conversions;

class QVBoxLayout;
class QPushButton;
class QLabel;

class WgtInputImage : public QScrollArea
{
    Q_OBJECT
public:
    WgtInputImage(QWidget *parent);

    void setImage(QString &fileName) const;
    QImage * getImage() const;

    void setController(Controller *controller);
    void addItemToCombobox(ImageConverterInfo *imageConverterInfo);

private:
    void makeConversion(Conversions conversion);

private slots:
        void onConvertButtonClick();

private:
    QVBoxLayout * mainLayout {nullptr};

    QLabel *inputImageTitle {nullptr};
    WgtImage *inputImage {nullptr};
    WgtDropDownFeatures *wgtDropDownFeatures {nullptr};
    QPushButton *convertBtn {nullptr};

    Controller *controller {nullptr};
};

#endif // WGTINPUTIMAGE_H
