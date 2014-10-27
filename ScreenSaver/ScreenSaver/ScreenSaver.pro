#-------------------------------------------------
#
# Project created by QtCreator 2014-10-23T20:54:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScreenSaver
TEMPLATE = app


SOURCES += main.cpp\
    screensaver.cpp \
    ss_triangle.cpp \
    ss_circles.cpp \
    mainwindow.cpp \
    ss_container.cpp \
    ss_boomerang.cpp

HEADERS  += \
    screensaver.h \
    ss_triangle.h \
    ss_circles.h \
    mainwindow.h \
    ss_container.h \
    ss_boomerang.h
