#-------------------------------------------------
#
# Project created by QtCreator 2017-11-16T14:58:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qdemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cameradialog.cpp \
    gallerydialog.cpp

HEADERS  += mainwindow.h \
    cameradialog.h \
    gallerydialog.h

FORMS    += mainwindow.ui \
    cameradialog.ui \
    gallerydialog.ui

RESOURCES += \
    MyResource.qrc
