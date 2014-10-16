#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *central = new QWidget;

    //this->setMinimumSize(treeWdgt.maximumSize());

    QHBoxLayout *lout = new QHBoxLayout;
    lout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QScrollArea *scroll_map = new QScrollArea;
    scroll_map->setWidget(&treeWdgt);
    lout->addWidget(scroll_map);

    central->setLayout(lout);

    setCentralWidget(central);
    setWindowTitle("AVLTree");
}

MainWindow::~MainWindow()
{
}
