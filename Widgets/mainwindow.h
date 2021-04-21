#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Controller;
class ImageConverterInfo;

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

    void setInputImage(QString &fileName);
    QImage * getInputImage();

    void setOutputImage(QString &fileName);
    QImage * getOutputImage();

    //QString conversion() const;

    //void deliverController(Controller *controller);
    void setController(Controller *controller);
    void addItemToCombobox(ImageConverterInfo * imageConverterInfo);

    void convert();
    void setInitialState();
private:
    QSplitter * mainSplitter {nullptr};

    WidgetCatalog * wgtCatalog {nullptr};
    WgtInputImage * wgtInputImage {nullptr};
    WgtOutputImage * wgtOutputImage {nullptr};

    Controller * controller {nullptr};
};
#endif // MAINWINDOW_H
