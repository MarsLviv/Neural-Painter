#include "wgtinputimage.h"
#include "Widgets/wgtimage.h"
#include "Utils/utilspicture.h"
#include "Helpers/constants.h"
#include "Conversion/imageconverter.h"
#include "Widgets/wgtdropdownfeatures.h"
#include "Widgets/mainwindow.h"

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

    connect(convertBtn, &QPushButton::clicked, this, &WgtInputImage::onConvertButtonClick);
}

void WgtInputImage::setImage(QString &fileName) const
{
    inputImage->setImage(fileName);
}

QImage *WgtInputImage::getImage() const
{
    return inputImage->getImage();
}

void WgtInputImage::setController(Controller *controller)
{
    this->controller = controller;
}

void WgtInputImage::addItemToCombobox(ImageConverterInfo *imageConverterInfo)
{
    wgtDropDownFeatures->addItemToCombobox(imageConverterInfo);
}

void WgtInputImage::makeConversion(Conversions conversion)
{
    auto mainWindowPtr = parent()->parent();                    // MainWindow <- QSplitter <- WgtInputImage
    auto myParent = qobject_cast<MainWindow *>(mainWindowPtr);

    auto converter = controller->makeConverter(conversion);
    auto convertedImagePath = converter->convert(getImage());
    myParent->setOutputImage(convertedImagePath);
    delete converter;
}

void WgtInputImage::onConvertButtonClick()
{
    int convetsionIndex = wgtDropDownFeatures->conversionIndex();
    makeConversion(static_cast<Conversions>(convetsionIndex));
}
