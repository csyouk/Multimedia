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
    musicdialog.cpp \
    cameradialog.cpp \
    musicthread.cpp

HEADERS  += mainwindow.h \
    musicdialog.h \
    cameradialog.h \
    musicthread.h

FORMS    += mainwindow.ui \
    musicdialog.ui \
    cameradialog.ui

RESOURCES += \
    MyResource.qrc
