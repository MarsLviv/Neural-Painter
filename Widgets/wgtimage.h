#ifndef WGTIMAGE_H
#define WGTIMAGE_H

#include<QScrollArea>

class QLabel;

class WgtImage : public QScrollArea
{
    Q_OBJECT

public:
    WgtImage(QWidget *parent = nullptr);

    void setImage(QString &fileName);
    QImage * getImage();

    void setPixmap();

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QLabel *inputPictureLabel {nullptr};
    QImage *image {nullptr};
};

#endif // WGTIMAGE_H
