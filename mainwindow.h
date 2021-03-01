#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class WidgetCatalog;
class WgtInputImage;
class WgtOutputImage;
class QVBoxLayout;
class QSplitter;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSplitter * mainSplitter {nullptr};

    //QLabel * outputImage {nullptr};

    WidgetCatalog * wgtCatalog {nullptr};

    WgtInputImage * wgtInputImage1 {nullptr};
    WgtOutputImage * wgtOutputImage {nullptr};

    //QScrollArea * wgtOutputImage {nullptr};

    //QImage imageOutput {nullptr};

    //QVBoxLayout* outputPictureLayout {nullptr};


    //QLabel * outputPictureLabel {nullptr};

    //QPushButton *saveBtn {nullptr};
    //QPushButton *exitBtn {nullptr};

    void createUI();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:




};
#endif // MAINWINDOW_H
