#include "ss_container.h"
#include <exception>

SS_container::SS_container(QWidget *parent) :
    QWidget(parent)
{
    selected = 0;
    wdgt_type = (wdg_type)0;

    // SS widgets

    WIDGETS_COUNT = 8;
    setMinimumSize(320 * 4, 240 * (WIDGETS_COUNT / 4));

    ssavers = new ScreenSaver*[WIDGETS_COUNT];

    ssavers[0] = new SS_circles;
    ssavers[1] = new SS_triangle;
    ssavers[2] = new SS_triangle;
    ssavers[3] = new SS_triangle;
    ssavers[4] = new SS_circles;
    ssavers[5] = new SS_circles;
    ssavers[6] = new SS_boomerang;
    ssavers[7] = new SS_boomerang;


    for (unsigned int i = 0; i < WIDGETS_COUNT; ++i)
        ssavers[i]->setMinimumSize(320, 240);

    lout = new QGridLayout;
    for (unsigned int i = 0; i < WIDGETS_COUNT; ++i)
        lout->addWidget(ssavers[i], i / 4, i % 4, Qt::AlignCenter);

    // Control widgets

    QComboBox *widget_indx = new QComboBox;
    widget_indx->setDuplicatesEnabled(false);
    connect(widget_indx, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSelectIndex(int)));
    for (unsigned int i = 0; i < WIDGETS_COUNT; ++i)
        widget_indx->addItem(QString(QChar(i + 48)).append(" widget"));

    QComboBox *type = new QComboBox;
    type->setDuplicatesEnabled(false);
    connect(type, SIGNAL(currentIndexChanged(int)), this, SLOT(slotSelectType(int)));
    for (int i = 0; i < WDGT_TYPE_LAST; ++i)
    {
        if (i == SS_TRIANGLE)
            type->addItem(QString("SS_triangle"));
        else if (i == SS_CIRCLES)
            type->addItem(QString("SS_circles"));
        else if (i == SS_BOOMERANG)
            type->addItem(QString("SS_boomerang"));
    }

    QPushButton *apply_btn = new QPushButton(QString("Apply"));
    connect(apply_btn, SIGNAL(clicked()), this, SLOT(slotUpdateWdgtGrid()));

    // Label widgets

    QLabel *lbl_selected = new QLabel(QString(QChar(selected + 48)));
    connect(widget_indx, SIGNAL(currentIndexChanged(int)), lbl_selected, SLOT(setNum(int)));

    QLabel *lbl_type;
    if (wdgt_type == SS_TRIANGLE)
        lbl_type = new QLabel(QString("SS_triangle"));
    else if (wdgt_type == SS_CIRCLES)
        lbl_type = new QLabel(QString("SS_circles"));
    else if (wdgt_type == SS_BOOMERANG)
        lbl_type = new QLabel(QString("SS_boomerang"));
    connect(type, SIGNAL(currentIndexChanged(QString)), lbl_type, SLOT(setText(QString)));

    lout->addWidget(lbl_selected, WIDGETS_COUNT / 4 + 3, 0, Qt::AlignCenter);
    lout->addWidget(lbl_type, WIDGETS_COUNT / 4 + 3, 1, Qt::AlignCenter);

    lout->addWidget(widget_indx, WIDGETS_COUNT / 4 + 2, 0, Qt::AlignCenter);
    lout->addWidget(type, WIDGETS_COUNT / 4 + 2, 1, Qt::AlignCenter);
    lout->addWidget(apply_btn, WIDGETS_COUNT / 4 + 2, 2, Qt::AlignCenter);

    setLayout(lout);
}

SS_container::~SS_container()
{
    for (unsigned int i = 0; i < WIDGETS_COUNT; ++i)
        delete ssavers[i];
    delete ssavers;
}

void SS_container::slotSelectIndex(int i)
{
    selected = i;
}

void SS_container::slotSelectType(int i)
{
    wdgt_type = (wdg_type)i;
}

void SS_container::slotUpdateWdgtGrid()
{
    if (wdgt_type == SS_TRIANGLE)
    {
        delete ssavers[selected];
        ssavers[selected] = new SS_triangle(this);
        ssavers[selected]->setMinimumSize(320, 240);
        lout->addWidget(ssavers[selected], selected / 4, selected % 4, Qt::AlignCenter);
        ssavers[selected]->show();
    } else if (wdgt_type == SS_CIRCLES)
    {
        delete ssavers[selected];
        ssavers[selected] = new SS_circles(this);
        ssavers[selected]->setMinimumSize(320, 240);
        lout->addWidget(ssavers[selected], selected / 4, selected % 4, Qt::AlignCenter);
        ssavers[selected]->show();
    } else if (wdgt_type == SS_BOOMERANG)
    {
        delete ssavers[selected];
        ssavers[selected] = new SS_boomerang(this);
        ssavers[selected]->setMinimumSize(320, 240);
        lout->addWidget(ssavers[selected], selected / 4, selected % 4, Qt::AlignCenter);
        ssavers[selected]->show();
    }
}
