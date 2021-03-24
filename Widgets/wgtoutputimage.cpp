#include "wgtoutputimage.h"
#include "Utils/utilspicture.h"
#include "Helpers/constants.h"
#include "Widgets/wgtimage.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>


WgtOutputImage::WgtOutputImage(QWidget *parent) : QScrollArea(parent)
{
    this->setWidgetResizable(true);

    mainLayout = new QVBoxLayout(this);

    // title
    outputImageTitle = new QLabel(Helpers::titleOutputImage, this);
    outputImageTitle->setAlignment(Helpers::alignmentOutputImageTitle);
    outputImageTitle->setStyleSheet(Helpers::styleOutputImageTitle);

    mainLayout->addWidget(outputImageTitle);

    // image
    outputImage = new WgtImage(this);

    mainLayout->addWidget(outputImage);

    auto pictureFile = Utils::randomPictureName();
    outputImage->setImage(pictureFile);

    saveBtn = new QPushButton(Helpers::titleSaveButton, this);
    saveBtn->setStyleSheet(Helpers::styleSaveButton);
    //auto height = convertBtn->height();
    //convertBtn->setGeometry((wgtDropDownFeatures->width() / 2), height);
    //convertBtn->set
    mainLayout->addWidget(saveBtn);

    exitBtn = new QPushButton(Helpers::titleExitButton, this);
    exitBtn->setStyleSheet(Helpers::styleExitButton);

    mainLayout->addWidget(exitBtn);

    this->setLayout(mainLayout);
}
