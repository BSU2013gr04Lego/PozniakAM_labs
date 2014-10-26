#include "screensaver.h"
#include <cmath>

ScreenSaver::ScreenSaver(QWidget *parent, int dx, int dy, float dphi) :
    QGLWidget(parent)
{
    resizeGL(1366, 768);
    m_x = m_y = m_phi = 0;
    m_dx = dx;
    m_dy = dy;
    m_dphi = dphi;

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(repaint()));
    m_timer->start(1);
}

ScreenSaver::~ScreenSaver()
{
    delete m_timer;
}

int ScreenSaver::getX() const
{
    return m_x;
}

int ScreenSaver::getY() const
{
    return m_y;
}

double ScreenSaver::getAngle() const
{
    return m_phi;
}

int ScreenSaver::getWidth() const
{
    return m_width;
}

int ScreenSaver::getHeight() const
{
    return m_height;
}

/*virtual*/ void ScreenSaver::initializeGL()
{
    qglClearColor(Qt::black);
}

/*virtual*/ void ScreenSaver::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)w, (GLint)h);
    m_height = h;
    m_width = w;
    emit widthChanged(w);
    emit heightChanged(h);
    glOrtho(0, w, h, 0, -1, 1);
}

/*virtual*/ void ScreenSaver::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int x_offset = getX();
    int y_offset = getY();

    int n = 8;
    glPointSize(2);
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        for (int i = 0; i < n; ++i)
        {
            double angle = 2 * 3.14 * i / n;
            int x = (int)(cos(angle) * 40 + x_offset);
            int y = (int)(sin(angle) * 40 + y_offset);
            glVertex2d(x, y);
        }
    glEnd();

    /*
    glBegin(GL_QUADS);
    glColor3f(1, 0.33, 0.66);
    glVertex2f(0, 100);
    glColor3f(0, 1, 0.17);
    glVertex2f(100, 100);
    glColor3f(1, 0, 1);
    glVertex2f(100, 0);
    glColor3f(0, 0, 0);
    glVertex2f(0, 0);
    glEnd();
    */
}

void ScreenSaver::SlotMoveForward()
{
    if (m_x + m_dx > m_width || m_x + m_dx < 0)
        m_dx = -m_dx;
    m_x += m_dx;

    if (m_y + m_dy > m_height || m_y + m_dy < 0)
        m_dy = -m_dy;
    m_y += m_dy;

    if (m_phi + m_dphi > 4000 * M_PI)
        m_phi -= 3998 * M_PI;
    m_phi += m_dphi;
}

void ScreenSaver::SlotMoveBack()
{
    if (m_x - m_dx > m_width || m_x - m_dx < 0)
        m_dx = -m_dx;
    m_x -= m_dx;

    if (m_y - m_dy > m_height || m_y - m_dy < 0)
        m_dy = -m_dy;
    m_y -= m_dy;

    if (m_phi - m_dphi < 2 * M_PI)
        m_phi += 2 * M_PI;
    m_phi -= m_dphi;
}

void ScreenSaver::repaint()
{
    //paintGL();
    update();
    SlotMoveForward();
}
