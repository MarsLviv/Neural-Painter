#include "mainwindow.h"

#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>

void MainWindow::createUI()
{
    mainSplitter = new QSplitter(Qt::Horizontal);

    //mainSplitter->setStretchFactor(0, 1);
    //mainSplitter->setStretchFactor(1, 2);
    //mainSplitter->setStretchFactor(2, 2);

    // directory tree
    wgtCatalog = new QWidget;

    catalogLayout = new QVBoxLayout;

    dirModel = new QFileSystemModel;
    dirModel->setRootPath(QDir::currentPath());
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    dirView = new QTreeView();
    dirView->setModel(dirModel);


    fileModel = new QFileSystemModel;
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    QString mPath = "";//"C:/";
    fileModel->setRootPath(mPath);

    fileView = new QListView();
    fileView->setModel(fileModel);

    catalogLayout->addWidget(dirView);
    catalogLayout->addWidget(fileView);
    catalogLayout->setContentsMargins(0, 0, 0, 0);

    wgtCatalog->setLayout(catalogLayout);

    mainSplitter->addWidget(wgtCatalog);

    connect(dirView, &QTreeView::clicked, this, &MainWindow::onTreeViewClicked);
    connect(dirView, &QTreeView::expanded, this, &MainWindow::onTreeViewClicked);

    // second splitter
    //imageSplitter = new QSplitter(Qt::Horizontal);

    // input image
    wgtInputImage = new QScrollArea;//QWidget;
    wgtInputImage->setWidgetResizable(true);

    inputPictureLayout = new QVBoxLayout;

    inputImage = new QLabel("INPUT IMAGE");

    inputPictureLabel = new QLabel;
    inputPictureLabel->setAlignment(Qt::AlignCenter);

    QString filename = ":resourcesPaints/LvivLarge1.jpg";//LvivLarge1
    QPixmap inputPixmap;
    if(inputPixmap.load(filename))
    {
        inputPixmap = inputPixmap.scaled(inputPictureLabel->size(), Qt::KeepAspectRatio);
        inputPictureLabel->setPixmap(inputPixmap);
        inputPictureLabel->setMask(inputPixmap.mask());
    }


    inputPictureLayout->addWidget(inputImage);
    inputPictureLayout->addWidget(inputPictureLabel);

    wgtInputImage->setLayout(inputPictureLayout);
    //imageSplitter->addWidget(wgtInputImage);
    mainSplitter->addWidget(wgtInputImage);

    // dropdown menu
    dropDownFeatures = new QComboBox();
    dropDownFeatures->addItem("item " + QString::number(1));
    dropDownFeatures->addItem("item " + QString::number(2));

    inputPictureLayout->addWidget(dropDownFeatures);
    // </> dropdown menu

    convertBtn = new QPushButton("Convert");
    inputPictureLayout->addWidget(convertBtn);

    // output image
    wgtOutputImage = new QScrollArea;//QWidget;
    wgtOutputImage->setWidgetResizable(true);

    outputPictureLayout = new QVBoxLayout;

    outputImage = new QLabel("CONVERTED IMAGE");

    outputPictureLabel = new QLabel;


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
    //imageSplitter->addWidget(wgtOutputImage);
    mainSplitter->addWidget(wgtOutputImage);

    //mainSplitter->addWidget(imageSplitter);

    exitBtn = new QPushButton("Exit");
    outputPictureLayout->addWidget(exitBtn);


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

void MainWindow::onTreeViewClicked(const QModelIndex &index)
{
    qDebug() << "onTreeViewClicked";

    QString mPath = dirModel->fileInfo(index).absoluteFilePath();
    qDebug() << "mPath" << mPath;
    fileView->setRootIndex(fileModel->setRootPath(mPath));
};





