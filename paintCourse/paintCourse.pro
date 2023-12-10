QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    correctioncommand.cpp \
    curve.cpp \
    drawcommand.cpp \
    drawingarea.cpp \
    ellipse.cpp \
    filledshape.cpp \
    filtraringcommand.cpp \
    flipcommand.cpp \
    imagesizeexception.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    resizecommand.cpp \
    rotatecommand.cpp \
    shape.cpp

HEADERS += \
    correctioncommand.h \
    curve.h \
    drawcommand.h \
    drawingarea.h \
    ellipse.h \
    filledshape.h \
    filtraringcommand.h \
    flipcommand.h \
    imagesizeexception.h \
    line.h \
    mainwindow.h \
    rectangle.h \
    resizecommand.h \
    rotatecommand.h \
    shape.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
