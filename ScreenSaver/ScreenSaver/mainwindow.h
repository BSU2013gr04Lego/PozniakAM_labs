#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QScrollArea>
#include "ss_container.h"
#include <exception>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    SS_container *m_wdgtCont;

public:
    explicit MainWindow(QWidget *parent = 0);

    MainWindow(const MainWindow &other)
    {
        throw std::exception();
    }

    MainWindow(MainWindow &&other)
    {
        throw std::exception();
    }

    void operator =(const MainWindow &other)
    {
        throw std::exception();
    }

    void operator =(MainWindow &&other)
    {
        throw std::exception();
    }

    ~MainWindow();

signals:

public slots:

};

#endif // MAINWINDOW_H
