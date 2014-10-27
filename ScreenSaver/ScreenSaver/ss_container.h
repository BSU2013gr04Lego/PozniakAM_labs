#ifndef SS_CONTAINER_H
#define SS_CONTAINER_H

#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "screensaver.h"
#include "ss_circles.h"
#include "ss_triangle.h"
#include "ss_boomerang.h"

//#define WIDGETS_COUNT 8

class SS_container : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *lout;
    ScreenSaver** ssavers;
    unsigned int WIDGETS_COUNT;

    int selected;
    enum wdg_type
    {
        SCREENSAVER,
        SS_TRIANGLE,
        SS_CIRCLES,
        SS_BOOMERANG,
        WDGT_TYPE_LAST
    } wdgt_type;

public:
    explicit SS_container(QWidget *parent = 0);

    SS_container(const SS_container &other)
    {
        throw std::exception();
    }

    SS_container(SS_container &&other)
    {
        throw std::exception();
    }

    void operator =(const SS_container &other)
    {
        throw std::exception();
    }

    void operator =(SS_container &&other)
    {
        throw std::exception();
    }
    ~SS_container();

signals:

private slots:
    void slotSelectIndex(int i);
    void slotSelectType(int i);
    void slotUpdateWdgtGrid();

public slots:

};

#endif // SS_CONTAINER_H
