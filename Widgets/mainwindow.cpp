﻿#include "mainwindow.h"
#include "wgtinputimage.h"
#include "wgtoutputimage.h"
#include "widgetcatalog.h"
#include "Helpers/constants.h"
#include "Conversion/imageconverter.h"

#include <QSplitter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createUI()
{
    mainSplitter = new QSplitter(Qt::Horizontal, this);

    // left column - Directory and File Explorer
    wgtCatalog = new WidgetCatalog(this);
    mainSplitter->addWidget(wgtCatalog);

    // middle column - input image
    wgtInputImage = new WgtInputImage(this);
    mainSplitter->addWidget(wgtInputImage);


    // right column - output image
    wgtOutputImage= new WgtOutputImage(this);
    mainSplitter->addWidget(wgtOutputImage);



    mainSplitter->setStretchFactor(0, Helpers::layoutProportions[0]);
    mainSplitter->setStretchFactor(1, Helpers::layoutProportions[1]);
    mainSplitter->setStretchFactor(2, Helpers::layoutProportions[2]);


    setCentralWidget(mainSplitter);
}

void MainWindow::setInputImage(QString &fileName) const
{
    wgtInputImage->setImage(fileName);
}

QImage *MainWindow::getInputImage() const
{
    return wgtInputImage->getImage();
}

void MainWindow::setOutputImage(QString &fileName) const
{
    wgtOutputImage->setImage(fileName);
}

QImage *MainWindow::getOutputImage() const
{
    return wgtOutputImage->getImage();
}


void MainWindow::setController(Controller *_controller)
{
    controller = _controller;
    wgtInputImage->setController(_controller);
}

void MainWindow::addItemToCombobox(ImageConverterInfo *imageConverterInfo)
{
    wgtInputImage->addItemToCombobox(imageConverterInfo);
}

void MainWindow::convert()
{
    auto convertedImagePath = controller->getConversion()->convert(getInputImage());
    setOutputImage(convertedImagePath);
}

void MainWindow::setInitialState()
{
    for(const auto converterInfo: controller->getConversionInfo())
        addItemToCombobox(converterInfo);

    convert();
}





