#include "ss_circles.h"

SS_circles::SS_circles(QWidget *parent, int x_offset, int y_offset) :
    ScreenSaver(parent)
{
    this->x_offset = getWidth() / 2;
    this->y_offset = getHeight() / 2;

    connect(this, SIGNAL(widthChanged(int)), SLOT(updateXOffset(int)));
    connect(this, SIGNAL(heightChanged(int)), SLOT(updateYOffset(int)));
}

SS_circles::~SS_circles()
{
}

/*virtual*/ void SS_circles::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int MAX_POINT_PER_CIRCLE = 50;
    double phi_offset = getAngle() / MAX_POINT_PER_CIRCLE;

    for (int n = 3; n < MAX_POINT_PER_CIRCLE; n++)
    {
        glPointSize(10);
        glBegin(GL_POINTS);
            glColor3f(1, 1, 1);
            for (int i = 0; i < n; ++i)
            {
                double angle = 2 * M_PI * i / n;
                int x = (int)(cos(angle + (MAX_POINT_PER_CIRCLE - n) * phi_offset) * 10 * n + x_offset);
                int y = (int)(sin(angle + (MAX_POINT_PER_CIRCLE - n) * phi_offset) * 10 * n + y_offset);
                glVertex2d(x, y);
            }
        glEnd();
    }
}

void SS_circles::updateXOffset(int width)
{
    x_offset = width / 2;
}

void SS_circles::updateYOffset(int height)
{
    y_offset = height / 2;
}
