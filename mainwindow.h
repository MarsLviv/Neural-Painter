#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QComboBox>
#include <QScrollArea>
#include <QPushButton>

#include "widgetcatalog.h"
//#include "wgtdropdownfeatures.h"

class WgtInputImage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSplitter * mainSplitter {nullptr};

    //QLabel * inputImageTitle {nullptr};
    QLabel * outputImage {nullptr};

    WidgetCatalog * wgtCatalog {nullptr};

    WgtInputImage * wgtInputImage1 {nullptr};

    //QScrollArea * wgtInputImage {nullptr};
    QScrollArea * wgtOutputImage {nullptr};

    //QScrollArea * wgtOutputImage1 {nullptr};

    QImage imageOutput {nullptr};

    //QVBoxLayout* inputPictureLayout {nullptr};
    QVBoxLayout* outputPictureLayout {nullptr};


    //WgtDropDownFeatures * wgtDropDownFeatures {nullptr};

    QLabel * outputPictureLabel {nullptr};

    //QPushButton *convertBtn {nullptr};
    QPushButton *saveBtn {nullptr};
    QPushButton *exitBtn {nullptr};

    void createUI();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:




};
#endif // MAINWINDOW_H
