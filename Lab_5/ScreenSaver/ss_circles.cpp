#include "ss_circles.h"
#include <exception>

SS_circles::SS_circles(QWidget *parent, double x_offset, double y_offset) :
    ScreenSaver(parent)
{
    this->x_offset = getWidth() / 2;
    this->y_offset = getHeight() / 2;

    connect(this, SIGNAL(widthChanged(int)), SLOT(updateXOffset(int)));
    connect(this, SIGNAL(heightChanged(int)), SLOT(updateYOffset(int)));
}

SS_circles::SS_circles(const SS_circles &other) :
    ScreenSaver(other)
{
    x_offset = other.x_offset;
    y_offset = other.y_offset;
}

SS_circles::SS_circles(SS_circles &&other) :
    ScreenSaver(other)
{
    x_offset = other.x_offset;
    y_offset = other.y_offset;
}

SS_circles &SS_circles::operator =(const SS_circles &other)
{
    setDX(other.getDX());
    setDY(other.getDY());
    setDAngle(other.getAngle());
    setX(other.getX());
    setY(other.getY());
    setAngle(other.getAngle());
    setHeight(other.getHeight());
    setWidth(other.getWidth());

    x_offset = other.x_offset;
    y_offset = other.y_offset;

    return *this;
}

SS_circles &SS_circles::operator =(SS_circles &&other)
{
    std::swap(*this, *(new SS_circles(other)));
    return *this;
}

SS_circles::~SS_circles()
{
}

void SS_circles::setXOffset(int x)
{
    x_offset = x;
}

void SS_circles::setYOffset(int y)
{
    y_offset = y;
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
                double x = (cos(angle + (MAX_POINT_PER_CIRCLE - n) * phi_offset) * 10 * n + x_offset);
                double y = (sin(angle + (MAX_POINT_PER_CIRCLE - n) * phi_offset) * 10 * n + y_offset);
                glVertex2d(x, y);
            }
        glEnd();
    }
}

void SS_circles::mousePressEvent(QMouseEvent *event)
{
    setDAngle(0);
    setPrevMouseX(event->globalX());
    setPrevMouseY(event->globalY());
}

void SS_circles::mouseReleaseEvent(QMouseEvent *event)
{
    double new_dphi = sqrt((event->globalX() - getPrevMouseX()) * (event->globalX() - getPrevMouseX()) +
                           (event->globalY() - getPrevMouseY()) * (event->globalY() - getPrevMouseY()));
    setDAngle(new_dphi / 1000);
}

void SS_circles::updateXOffset(int width)
{
    x_offset = width / 2;
}

void SS_circles::updateYOffset(int height)
{
    y_offset = height / 2;
}
