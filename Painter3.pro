QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cpp \
    Conversion/grayscaleconverter.cpp \
    Conversion/imageconverter.cpp \
    Conversion/mirrorconverter.cpp \
    Widgets/mainwindow.cpp \
    Widgets/wgtdropdownfeatures.cpp \
    Widgets/wgtimage.cpp \
    Widgets/wgtinputimage.cpp \
    Widgets/wgtoutputimage.cpp \
    Widgets/widgetcatalog.cpp \
    main.cpp \
    Utils/applocation.cpp

HEADERS += \
    Controller/controller.h \
    Conversion/grayscaleconverter.h \
    Conversion/imageconverter.h \
    Conversion/mirrorconverter.h \
    Helpers/constants.h \
    Utils/utilspicture.h \
    Utils/applocation.h \
    Widgets/mainwindow.h \
    Widgets/wgtdropdownfeatures.h \
    Widgets/wgtimage.h \
    Widgets/wgtinputimage.h \
    Widgets/wgtoutputimage.h \
    Widgets/widgetcatalog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    paints.qrc
