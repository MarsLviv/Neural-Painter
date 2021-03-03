#include "wgtoutputimage.h"
#include "Utils/utilspicture.h"

#include<wgtimage.h>

#include<QPushButton>
#include<QVBoxLayout>
#include<QLabel>


WgtOutputImage::WgtOutputImage(QWidget *parent) : QScrollArea(parent)
{
    this->setWidgetResizable(true);

    mainLayout = new QVBoxLayout(this);

    // title
    outputImageTitle = new QLabel("OUTPUT IMAGE", this);// TODO: move to settings
    outputImageTitle->setAlignment(Qt::AlignCenter);
    //https://doc.qt.io/qt-5/stylesheet-reference.html
    // TODO: move to settings
    outputImageTitle->setStyleSheet("QLabel {    background-color : grey; padding: 6px; "
                                    " font : Times New Roman;  font-size: 24px; font-style: italic;"
                                    " color : blue; border-radius : 10px; border-style : outset; border-width : 2px; border-color : beige; }");

    mainLayout->addWidget(outputImageTitle);

    // image
    outputImage = new WgtImage(this);
    mainLayout->addWidget(outputImage);

    //QString fileName(":resourcesPaints/LvivLarge1.jpg");
    auto pictureNumber = Utils::randomPictureName();
    QString fileName(":Lviv1.jpg");
    outputImage->setImage(fileName);



    saveBtn = new QPushButton("Save ...", this);
    saveBtn->setStyleSheet("QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 16px; "
                                    " color : black;  }");
    //auto height = convertBtn->height();
    //convertBtn->setGeometry((wgtDropDownFeatures->width() / 2), height);
    //convertBtn->set
    mainLayout->addWidget(saveBtn);

    exitBtn = new QPushButton("Exit", this);
    exitBtn->setStyleSheet("QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }");

    mainLayout->addWidget(exitBtn);

    this->setLayout(mainLayout);
}
