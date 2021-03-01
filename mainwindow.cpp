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

    // left column - Directory and File Explorer
    wgtCatalog = new WidgetCatalog();
    mainSplitter->addWidget(wgtCatalog);

    // middle column - input image
    wgtInputImage1 = new WgtInputImage(this);
    mainSplitter->addWidget(wgtInputImage1);


    // right column - output image
    wgtOutputImage= new WgtOutputImage(this);
    mainSplitter->addWidget(wgtOutputImage);



    mainSplitter->setStretchFactor(0, 2); // TODO: move to Settings
    mainSplitter->setStretchFactor(1, 5);
    mainSplitter->setStretchFactor(2, 5);


    setCentralWidget(mainSplitter);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createUI();
}

MainWindow::~MainWindow()
{

}







