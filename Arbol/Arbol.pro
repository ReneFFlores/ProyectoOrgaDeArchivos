#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T15:59:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arbol
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    index.cpp \
    btree.cpp

HEADERS  += mainwindow.h \
    node.h \
    index.h \
    btree.h

FORMS    += mainwindow.ui
