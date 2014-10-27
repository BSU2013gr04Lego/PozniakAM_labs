#ifndef SS_CONTAINER_H
#define SS_CONTAINER_H

#include <QWidget>
#include <QGridLayout>
#include "screensaver.h"
#include "ss_circles.h"
#include "ss_triangle.h"
#include "ss_boomerang.h"

#define WIDGETS_COUNT 8

class SS_container : public QWidget
{
    Q_OBJECT
private:
    ScreenSaver** ssavers;

public:
    explicit SS_container(QWidget *parent = 0);
    ~SS_container();

signals:

public slots:

};

#endif // SS_CONTAINER_H
