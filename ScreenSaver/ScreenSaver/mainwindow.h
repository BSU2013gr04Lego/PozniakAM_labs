#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QScrollArea>
#include "ss_container.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    SS_container *m_wdgtCont;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:

};

#endif // MAINWINDOW_H
