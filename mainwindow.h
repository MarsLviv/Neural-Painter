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

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLabel * inputImage;
    QLabel * outputImage;

    QSplitter * mainSplitter;
    //QSplitter * imageSplitter;

    QWidget * wgtCatalog;
    //QWidget * wgtInputImage;
    //QWidget * wgtOutputImage;
    QScrollArea * wgtInputImage;
    QScrollArea * wgtOutputImage;


    QVBoxLayout* catalogLayout;
    QVBoxLayout* inputPictureLayout;
    QVBoxLayout* outputPictureLayout;


    //QLabel * label1;
    //QLabel * label2;
    //QLabel * label3;
    QLabel * inputPictureLabel;
    QLabel * outputPictureLabel;



    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;

    QTreeView *dirView;
    QListView *fileView;

    QComboBox *dropDownFeatures;

    QPushButton *convertBtn;
    QPushButton *exitBtn;

    void createUI();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onTreeViewClicked(const QModelIndex &index);



};
#endif // MAINWINDOW_H
