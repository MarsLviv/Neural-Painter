#include "mainwindow.h"
#include "wgtimage.h"
#include "wgtinputimage.h"
#include "wgtoutputimage.h"
#include "widgetcatalog.h"

#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QApplication>
#include <QScreen>
#include <QLabel>
#include <QImageReader>
#include <QMessageBox>
#include <QImage>
#include <QColorSpace>
#include <QBoxLayout>
#include <QSplitter>

void MainWindow::createUI()
{
    mainSplitter = new QSplitter(Qt::Horizontal);

    // Directory and File Explorer
    wgtCatalog = new WidgetCatalog();
    mainSplitter->addWidget(wgtCatalog);

    // middle column - input image
    wgtInputImage1 = new WgtInputImage(this);
    mainSplitter->addWidget(wgtInputImage1);


    // right column - output image
    wgtOutputImage= new WgtOutputImage(this);
    mainSplitter->addWidget(wgtOutputImage);


    // right column - output image
    /*wgtOutputImage = new QScrollArea;
    wgtOutputImage->setWidgetResizable(true);


    outputPictureLayout = new QVBoxLayout;

    outputImage = new QLabel("CONVERTED IMAGE");

    outputPictureLabel = new QLabel;
    QString filename;
    filename = ":resourcesPaints/Lviv3.jpg";
    outputPictureLabel->setAlignment(Qt::AlignCenter);
    QPixmap outputPixmap;
    if(outputPixmap.load(filename))
    {
        outputPixmap = outputPixmap.scaled(outputPictureLabel->size(), Qt::KeepAspectRatio);
        outputPictureLabel->setPixmap(outputPixmap);
    }

    outputPictureLayout->addWidget(outputImage);
    outputPictureLayout->addWidget(outputPictureLabel);

    wgtOutputImage->setLayout(outputPictureLayout);

    mainSplitter->addWidget(wgtOutputImage);


    saveBtn = new QPushButton("Save Image ...");
    outputPictureLayout->addWidget(saveBtn);

    exitBtn = new QPushButton("Exit");
    outputPictureLayout->addWidget(exitBtn);*/

    mainSplitter->setStretchFactor(0, 2); // TODO: move to Settings
    mainSplitter->setStretchFactor(1, 5);
    mainSplitter->setStretchFactor(2, 5);
    //mainSplitter->setSizes(QList<int>({INT_MAX, INT_MAX, INT_MAX}));


    setCentralWidget(mainSplitter);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createUI();
}

MainWindow::~MainWindow()
{

}







