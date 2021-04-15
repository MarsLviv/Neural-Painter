#include "wgtinputimage.h"
#include "Utils/utilspicture.h"
#include "Widgets/wgtimage.h"
#include "Widgets/wgtdropdownfeatures.h"
#include "Helpers/constants.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>


WgtInputImage::WgtInputImage(QWidget *parent) : QScrollArea(parent)
{
    this->setWidgetResizable(true);

    mainLayout = new QVBoxLayout(this);

    // title
    inputImageTitle = new QLabel(Helpers::titleInputImage, this);
    inputImageTitle->setAlignment(Helpers::alignmentInputImageTitle);
    inputImageTitle->setStyleSheet(Helpers::styleInputImageTitle);

    mainLayout->addWidget(inputImageTitle);

    // image
    inputImage = new WgtImage(this);

    mainLayout->addWidget(inputImage);

    auto pictureFile = Utils::randomPictureName();
    inputImage->setImage(pictureFile);

    // dropdown menu
    wgtDropDownFeatures = new WgtDropDownFeatures(this);
    mainLayout->addWidget(wgtDropDownFeatures);

    convertBtn = new QPushButton(Helpers::titleConvertButton, this);
    convertBtn->setStyleSheet(Helpers::styleConvertButton);
    //auto height = convertBtn->height();
    //convertBtn->setGeometry((wgtDropDownFeatures->width() / 2), height);
    //convertBtn->set
    mainLayout->addWidget(convertBtn);

    this->setLayout(mainLayout);
}

void WgtInputImage::setImage(QString &fileName)
{
    inputImage->setImage(fileName);
}

QImage *WgtInputImage::getImage()
{
    return inputImage->getImage();
}

QString WgtInputImage::conversion() const
{
    return wgtDropDownFeatures->conversion();
}
