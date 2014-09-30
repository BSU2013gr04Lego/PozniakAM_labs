#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T10:22:13
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AVLTree
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += TreeWidget.cpp \
    AVLTree.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS  += \
    mainwindow.h \
    TreeWidget.h \
    AVLTree.h \
    AVLNode.h
