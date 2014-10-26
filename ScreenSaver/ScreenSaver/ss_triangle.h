#ifndef SS_TRIANGLE_H
#define SS_TRIANGLE_H

#include "screensaver.h"
#include <cmath>

class SS_triangle : public ScreenSaver
{
    Q_OBJECT
public:
    explicit SS_triangle(QWidget *parent = 0);
    ~SS_triangle();

protected:
    virtual void paintGL();
};

#endif // SS_TRIANGLE_H
