#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_wdgtCont = new SS_container;

    QScrollArea *scroll_map = new QScrollArea;
    scroll_map->setWidget(m_wdgtCont);

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
}
