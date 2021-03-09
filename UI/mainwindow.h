#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class WidgetCatalog;
class WgtInputImage;
class WgtOutputImage;
class QSplitter;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void createUI();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSplitter * mainSplitter {nullptr};

    WidgetCatalog * wgtCatalog {nullptr};
    WgtInputImage * wgtInputImage1 {nullptr};
    WgtOutputImage * wgtOutputImage {nullptr};
};
#endif // MAINWINDOW_H
