#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QBoxLayout>
#include <QScrollArea>
#include <screensaver.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    ScreenSaver m_saver;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
