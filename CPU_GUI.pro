#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T20:18:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPU_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Pipe.cpp

HEADERS  += mainwindow.h \
    pipe.h \
    bin2ins.h

FORMS    += mainwindow.ui
CONFIG += c++11
