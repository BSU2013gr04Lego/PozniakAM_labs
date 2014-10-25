#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QBoxLayout>
#include <QScrollArea>
#include <TreeWidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    TreeWidget treeWdgt;

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
