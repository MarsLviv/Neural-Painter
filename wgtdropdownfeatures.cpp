#include "wgtdropdownfeatures.h"

#include<QLabel>
#include<QHBoxLayout>
#include<QComboBox>

WgtDropDownFeatures::WgtDropDownFeatures(QWidget *parent) : QWidget(parent)
{
    QStringList efects = {"Night", "Colorization", "Google Deep Dream"};// TODO: move to settings / other class

    mainLayout = new QHBoxLayout(this);

    title = new QLabel("Select Conversion", this);
    title->setAlignment(Qt::AlignCenter);
    // TODO: move to settings
    title->setStyleSheet("QLabel {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }");
    mainLayout->addWidget(title);

    dropDownFeatures = new QComboBox(this);
    // TODO: move to settings
    dropDownFeatures->setStyleSheet("QComboBox {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }");

    for (int i = 0; i < efects.size(); ++i)
        dropDownFeatures->addItem(efects[i]);

    mainLayout->addWidget(dropDownFeatures);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}
