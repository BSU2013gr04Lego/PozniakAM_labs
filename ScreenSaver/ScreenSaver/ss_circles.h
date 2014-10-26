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
    int x_offset;
    int y_offset;

public:
    explicit SS_circles(QWidget *parent = 0, int x_offset = SCIR_X_POSITION, int y_offset = SCIR_Y_POSITION);
    ~SS_circles();

protected:
    virtual void paintGL();

public slots:
    void updateXOffset(int width);
    void updateYOffset(int height);
};

#endif // SS_CIRCLES_H
