#include "ss_triangle.h"

SS_triangle::SS_triangle(QWidget *parent) :
    ScreenSaver(parent)
{
}

SS_triangle::~SS_triangle()
{
}

/*virtual*/ void SS_triangle::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int x_offset = getX();
    int y_offset = getY();
    double phi_offset = getAngle();

    int n = 3;
    glPointSize(2);
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        for (int i = 0; i < n; ++i)
        {
            double angle = 2 * M_PI * i / n;
            int x = (int)(cos(angle + phi_offset) * 40 + x_offset);
            int y = (int)(sin(angle + phi_offset) * 40 + y_offset);
            glVertex2d(x, y);
        }
    glEnd();
}
