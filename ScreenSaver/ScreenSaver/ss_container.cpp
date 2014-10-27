#include "ss_container.h"

SS_container::SS_container(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(320 * 4, 240 * (WIDGETS_COUNT / 4));

    ssavers = new ScreenSaver*[WIDGETS_COUNT];
    ssavers[0] = new SS_circles;
    ssavers[1] = new SS_triangle;
    ssavers[2] = new ScreenSaver;
    ssavers[3] = new SS_triangle;
    ssavers[4] = new ScreenSaver;
    ssavers[5] = new SS_circles;
    ssavers[6] = new SS_boomerang;
    ssavers[7] = new SS_boomerang;

    for (int i = 0; i < WIDGETS_COUNT; ++i)
        ssavers[i]->setMinimumSize(320, 240);

    QGridLayout *lout = new QGridLayout;
    for (int i = 0; i < WIDGETS_COUNT; ++i)
        lout->addWidget(ssavers[i], i / 4, i % 4, Qt::AlignCenter);

    setLayout(lout);
}

SS_container::~SS_container()
{
    for (int i = 0; i < WIDGETS_COUNT; ++i)
        delete ssavers[i];
    delete ssavers;
}
