#include "ss_triangle.h"

SS_triangle::SS_triangle(QWidget *parent) :
    ScreenSaver(parent)
{
    setDX(SSAV_X_SPEED / 3.14);
    setDY(SSAV_Y_SPEED / 6);
}

SS_triangle::~SS_triangle()
{
}

/*virtual*/ void SS_triangle::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double x_offset = getX();
    double y_offset = getY();
    double phi_offset = getAngle();

    int n = 3;
    glPointSize(2);
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        for (int i = 0; i < n; ++i)
        {
            double angle = 2 * M_PI * i / n;
            double x = (cos(angle + phi_offset) * 40 + x_offset);
            double y = (sin(angle + phi_offset) * 40 + y_offset);
            glVertex2d(x, y);
        }
    glEnd();
}
