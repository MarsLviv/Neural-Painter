#include "wgtimage.h"

#include <QApplication>
#include <QImageReader>
#include <QMessageBox>
#include <QColorSpace>
#include <QScreen>
#include <QImage>
#include <QLabel>
#include <QDir>

#include "Helpers/constants.h"

WgtImage::WgtImage(QWidget *parent) : QScrollArea(parent)
{
    inputPictureLabel = new QLabel(this);

    inputPictureLabel->setBackgroundRole(QPalette::Base);
    inputPictureLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    inputPictureLabel->setScaledContents(true);

    this->setBackgroundRole(QPalette::Dark);
    this->setWidget(inputPictureLabel);
    this->setVisible(true);
    setAlignment(Qt::AlignCenter);
}

void WgtImage::setImage(QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    if (image)
    {
        delete image;
    }

    image = new QImage(reader.read());
    if (image->isNull())
    {
        QMessageBox::information(this,
                                 QGuiApplication::applicationDisplayName(),
                                 Helpers::titleErrorMessage
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return;
    }

    if (image->colorSpace().isValid())
    {
        image->convertToColorSpace(QColorSpace::SRgb);
        return;
    }
    setPixmap();
}

QImage *WgtImage::getImage()
{
    return image;
}

void WgtImage::setPixmap()
{
    inputPictureLabel->setPixmap(QPixmap::fromImage(*image).scaled(this->width(), this->height(), Qt::KeepAspectRatio));
    inputPictureLabel->adjustSize();
}

void WgtImage::resizeEvent(QResizeEvent *event)
{
    setPixmap();

    QWidget::resizeEvent(event);
}
