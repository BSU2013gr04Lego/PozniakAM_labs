#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include "screensaver.h"
#include "ss_circles.h"
#include "ss_triangle.h"

#define WIDGETS_COUNT 6

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    ScreenSaver** ssavers;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:

};

#endif // MAINWINDOW_H
