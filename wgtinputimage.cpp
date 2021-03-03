#include "wgtinputimage.h"

#include<wgtimage.h>
#include<wgtdropdownfeatures.h>

#include<QPushButton>
#include<QVBoxLayout>
#include<QLabel>


WgtInputImage::WgtInputImage(QWidget *parent) : QScrollArea(parent)
{
    this->setWidgetResizable(true);

    mainLayout = new QVBoxLayout(this);

    // title
    inputImageTitle = new QLabel("INPUT IMAGE", this);// TODO: move to settings
    inputImageTitle->setAlignment(Qt::AlignCenter);
    //https://doc.qt.io/qt-5/stylesheet-reference.html
    // TODO: move to settings
    inputImageTitle->setStyleSheet("QLabel {    background-color : grey; padding: 6px; "
                                    " font : Times New Roman;  font-size: 24px; font-style: italic;"
                                    " color : blue; border-radius : 10px; border-style : outset; border-width : 2px; border-color : beige; }");

    mainLayout->addWidget(inputImageTitle);

    // image
    inputImage = new WgtImage(this);

    mainLayout->addWidget(inputImage);
    //QString fileName(":resourcesPaints/LvivLarge1.jpg");
    QString fileName(":Lviv1.jpg");
    inputImage->setImage(fileName);

    // dropdown menu
    wgtDropDownFeatures = new WgtDropDownFeatures(this);
    mainLayout->addWidget(wgtDropDownFeatures);

    convertBtn = new QPushButton("Convert", this);
    convertBtn->setStyleSheet("QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }");
    //auto height = convertBtn->height();
    //convertBtn->setGeometry((wgtDropDownFeatures->width() / 2), height);
    //convertBtn->set
    mainLayout->addWidget(convertBtn);

    this->setLayout(mainLayout);
}
