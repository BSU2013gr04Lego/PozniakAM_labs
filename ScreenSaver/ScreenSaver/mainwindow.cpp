#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ssavers = new ScreenSaver*[WIDGETS_COUNT];
    ssavers[0] = new SS_circles;
    ssavers[1] = new SS_triangle;
    ssavers[2] = new ScreenSaver;
    ssavers[3] = new SS_triangle;
    ssavers[4] = new ScreenSaver;
    ssavers[5] = new SS_circles;

    for (int i = 0; i < WIDGETS_COUNT; ++i)
        ssavers[i]->setMinimumSize(300, 300);


    QGridLayout *lout = new QGridLayout;
    for (int i = 0; i < WIDGETS_COUNT; ++i)
        lout->addWidget(ssavers[i], i / 3, i % 3, Qt::AlignCenter);

    QScrollArea *scroll_map = new QScrollArea;
    scroll_map->setLayout(lout);

    QHBoxLayout *hlout = new QHBoxLayout;
    hlout->setAlignment(Qt::AlignLeft);
    hlout->addWidget(scroll_map);

    QWidget *central = new QWidget;
    central->setLayout(hlout);

    setCentralWidget(central);
    setWindowTitle("ScreenSavers");
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < WIDGETS_COUNT; ++i)
        delete ssavers[i];
    delete ssavers;
}
