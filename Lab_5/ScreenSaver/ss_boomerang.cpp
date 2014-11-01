#include "ss_boomerang.h"

SS_boomerang::SS_boomerang(QWidget *parent) :
    ScreenSaver(parent)
{
}

SS_boomerang::SS_boomerang(const SS_boomerang &other) :
    ScreenSaver(other)
{
}

SS_boomerang::SS_boomerang(SS_boomerang &&other) :
    ScreenSaver(other)
{
}

SS_boomerang &SS_boomerang::operator =(const SS_boomerang &other)
{
    setDX(other.getDX());
    setDY(other.getDY());
    setDAngle(other.getAngle());
    setX(other.getX());
    setY(other.getY());
    setAngle(other.getAngle());
    setHeight(other.getHeight());
    setWidth(other.getWidth());

    return *this;
}

SS_boomerang &SS_boomerang::operator =(SS_boomerang &&other)
{
    std::swap(*this, *(new SS_boomerang(other)));
    return *this;
}

SS_boomerang::~SS_boomerang()
{
}


/*virtual*/ void SS_boomerang::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double x_offset = getX();
    double y_offset = getY();
    double phi_offset = 10 * getAngle();

    glPointSize(2);
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1, 1, 1);
        double angle = 0;
        double x = (cos(angle + phi_offset) * 50 + x_offset);
        double y = (sin(angle + phi_offset) * 50 + y_offset);
        glVertex2d(x, y);

        angle = M_PI / 2;
        x = (cos(angle + phi_offset) * 30 + x_offset);
        y = (sin(angle + phi_offset) * 30 + y_offset);
        glVertex2d(x, y);

        angle = M_PI / 2;
        x = (cos(angle + phi_offset) * 60 + x_offset);
        y = (sin(angle + phi_offset) * 60 + y_offset);
        glVertex2d(x, y);

        angle = M_PI;
        x = (cos(angle + phi_offset) * 50 + x_offset);
        y = (sin(angle + phi_offset) * 50 + y_offset);
        glVertex2d(x, y);
    glEnd();
}

void SS_boomerang::mousePressEvent(QMouseEvent *event)
{
    setDAngle(0);
    setDX(0);
    setDY(0);
    setPrevMouseX(event->globalX());
    setPrevMouseY(event->globalY());
}

void SS_boomerang::mouseReleaseEvent(QMouseEvent *event)
{
    double new_dphi = sqrt((event->globalX() - getPrevMouseX()) * (event->globalX() - getPrevMouseX()) +
                           (event->globalY() - getPrevMouseY()) * (event->globalY() - getPrevMouseY()));
    setDX((event->globalX() - getPrevMouseX()) / 50);
    setDY((event->globalY() - getPrevMouseY()) / 50);
    setDAngle(new_dphi / 10000);
}
