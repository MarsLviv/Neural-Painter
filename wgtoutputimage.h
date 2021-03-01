#ifndef WGTOUTPUTIMAGE_H
#define WGTOUTPUTIMAGE_H

#include<QScrollArea>

class QVBoxLayout;
class QPushButton;
class QLabel;

class WgtImage;

/*  Class implements Output picture and buttons to Save it and Exit from app
 *  For details see UML Hierarchy diagram
 */
class WgtOutputImage : public QScrollArea
{
    Q_OBJECT
public:
    WgtOutputImage(QWidget *parent);


private:
    QVBoxLayout * mainLayout {nullptr};

    QLabel * outputImageTitle {nullptr};
    WgtImage * outputImage {nullptr};
    QPushButton * saveBtn {nullptr};
    QPushButton * exitBtn {nullptr};

};

#endif // WGTOUTPUTIMAGE_H
