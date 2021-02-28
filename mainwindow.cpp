#include "mainwindow.h"
#include "wgtimage.h"

#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QApplication>
#include <QScreen>
#include <QImageReader>
#include <QMessageBox>
#include <QImage>
#include <QColorSpace>


void MainWindow::createUI()
{
    mainSplitter = new QSplitter(Qt::Horizontal);

    // Directory and File Explorer
    wgtCatalog = new WidgetCatalog();
    mainSplitter->addWidget(wgtCatalog);


    // middle column
    wgtInputImage = new QScrollArea;
    wgtInputImage->setWidgetResizable(true);

    inputPictureLayout = new QVBoxLayout(this);

    // title
    inputImageTitle = new QLabel("INPUT IMAGE", this);
    inputImageTitle->setAlignment(Qt::AlignCenter);
    //https://doc.qt.io/qt-5/stylesheet-reference.html
    // TODO: move to settings
    inputImageTitle->setStyleSheet("QLabel {    background-color : grey; padding: 6px; "
                                    " font : Times New Roman;  font-size: 24px; font-style: italic;"
                                    " color : blue; border-radius : 10px; border-style : outset; border-width : 2px; border-color : beige; }");

    inputPictureLayout->addWidget(inputImageTitle);

    // image
    WgtImage *inputImage = new WgtImage(this);

    inputPictureLayout->addWidget(inputImage);
    QString fileName(":resourcesPaints/LvivLarge1.jpg");
    inputImage->setImage(fileName);

    // dropdown menu
    wgtDropDownFeatures = new WgtDropDownFeatures(this);
    inputPictureLayout->addWidget(wgtDropDownFeatures);

    convertBtn = new QPushButton("Convert", this);
    convertBtn->setStyleSheet("QPushButton {    background-color : grey; "
                                    " font : Times New Roman;  font-size: 20px; "
                                    " color : black;  }");
    //auto height = convertBtn->height();
    //convertBtn->setGeometry((wgtDropDownFeatures->width() / 2), height);
    //convertBtn->set
    inputPictureLayout->addWidget(convertBtn);

    wgtInputImage->setLayout(inputPictureLayout);

    mainSplitter->addWidget(wgtInputImage);

    // output image
    wgtOutputImage = new QScrollArea;
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
    outputPictureLayout->addWidget(exitBtn);

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







