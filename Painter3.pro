QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Utils/applocation.cpp \
    UI/mainwindow.cpp \
    UI/wgtdropdownfeatures.cpp \
    UI/wgtimage.cpp \
    UI/wgtinputimage.cpp \
    UI/wgtoutputimage.cpp \
    UI/widgetcatalog.cpp

HEADERS += \
    Utils/utilspicture.h \
    Utils/applocation.h \
    UI/mainwindow.h \
    UI/wgtdropdownfeatures.h \
    UI/wgtimage.h \
    UI/wgtinputimage.h \
    UI/wgtoutputimage.h \
    UI/widgetcatalog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    paints.qrc
