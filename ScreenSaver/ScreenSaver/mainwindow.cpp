#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget;

    setMinimumSize(m_saver.sizeHint());

    QHBoxLayout *lout = new QHBoxLayout;
    lout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QScrollArea *scroll_map = new QScrollArea;
    scroll_map->setWidget(&m_saver);
    lout->addWidget(scroll_map);

    central->setLayout(lout);

    setCentralWidget(central);
    setWindowTitle("Labirinth");
}

MainWindow::~MainWindow()
{

}
