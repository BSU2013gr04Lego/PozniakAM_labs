#ifndef SS_CIRCLES_H
#define SS_CIRCLES_H

#include "screensaver.h"
#include <cmath>

#define SCIR_X_POSITION 683
#define SCIR_Y_POSITION 384

class SS_circles : public ScreenSaver
{
    Q_OBJECT
private:
    double x_offset;
    double y_offset;

public:
    explicit SS_circles(QWidget *parent = 0, double x_offset = SCIR_X_POSITION, double y_offset = SCIR_Y_POSITION);
    ~SS_circles();

    void setXOffset(int x);
    void setYOffset(int y);

protected:
    virtual void paintGL();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void updateXOffset(int width);
    void updateYOffset(int height);
};

#endif // SS_CIRCLES_H
