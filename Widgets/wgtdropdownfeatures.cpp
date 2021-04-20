#include "wgtdropdownfeatures.h"
#include "Helpers/constants.h"
#include "Conversion/imageconverter.h"

#include<QLabel>
#include<QHBoxLayout>
#include<QComboBox>

WgtDropDownFeatures::WgtDropDownFeatures(QWidget *parent) : QWidget(parent)
{
    //QStringList efects = {"Mirror", "Grayscale", "Colorization", "Google Deep Dream"};// TODO: move to settings / other class

    mainLayout = new QHBoxLayout(this);

    title = new QLabel(Helpers::titleDropdownMenuLabel, this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(Helpers::styleDropdownMenuLabel);
    mainLayout->addWidget(title);

    dropDownFeatures = new QComboBox(this);
    dropDownFeatures->setStyleSheet(Helpers::styleDropdownMenuList);
    /*dropDownFeatures->setStyleSheet("QComboBox {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 24px; "
                                    " color : black;  }");*/


//    for (int i = 0; i < efects.size(); ++i)
//        dropDownFeatures->addItem(efects[i]);

    mainLayout->addWidget(dropDownFeatures);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

QString WgtDropDownFeatures::conversion() const
{           //dropDownFeatures->currentIndex();
    return dropDownFeatures->currentText();
}

void WgtDropDownFeatures::addItemToCombobox(ImageConverter * imageConverter)
{
    dropDownFeatures->addItem(imageConverter->name(), static_cast<int>(imageConverter->itemValue()));
}

void WgtDropDownFeatures::deliverController(Controller * controller)
{
    for(const auto converter: controller->getConversionInstances())
        addItemToCombobox(converter);
}
