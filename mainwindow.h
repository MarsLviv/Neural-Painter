#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSplitter>
#include <QScrollArea>
#include <QPushButton>

class WidgetCatalog;
class WgtInputImage;
class QVBoxLayout;
class QLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSplitter * mainSplitter {nullptr};

    QLabel * outputImage {nullptr};

    WidgetCatalog * wgtCatalog {nullptr};

    WgtInputImage * wgtInputImage1 {nullptr};

    QScrollArea * wgtOutputImage {nullptr};

    QImage imageOutput {nullptr};

    QVBoxLayout* outputPictureLayout {nullptr};


    QLabel * outputPictureLabel {nullptr};

    QPushButton *saveBtn {nullptr};
    QPushButton *exitBtn {nullptr};

    void createUI();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:




};
#endif // MAINWINDOW_H
