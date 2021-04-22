#include "wgtdropdownfeatures.h"
#include "Helpers/constants.h"
#include "Conversion/imageconverter.h"

#include<QLabel>
#include<QHBoxLayout>
#include<QComboBox>

WgtDropDownFeatures::WgtDropDownFeatures(QWidget *parent) : QWidget(parent)
{
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

    mainLayout->addWidget(dropDownFeatures);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

QString WgtDropDownFeatures::conversion() const
{
    return dropDownFeatures->currentText();
}

int WgtDropDownFeatures::conversionIndex() const
{
    dropDownFeatures->currentIndex();
}

void WgtDropDownFeatures::addItemToCombobox(ImageConverterInfo * imageConverterInfo)
{
    dropDownFeatures->addItem(imageConverterInfo->name(), static_cast<int>(imageConverterInfo->itemValue()));
}

//void WgtDropDownFeatures::deliverController(Controller * controller)
//{
//    for(const auto converterInfo: controller->getConversionInfo())
//        addItemToCombobox(converterInfo);
//}
