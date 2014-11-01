#include "screensaver.h"
#include <cmath>

ScreenSaver::ScreenSaver(QWidget *parent, double dx, double dy, double dphi) :
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

ScreenSaver::ScreenSaver(const ScreenSaver &other) :
    QGLWidget(other.parentWidget())
{
    this->m_dx = other.m_dx;
    this->m_dy = other.m_dy;
    this->m_dphi = other.m_dphi;
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->m_phi = other.m_phi;
    this->m_height = other.m_height;
    this->m_width = other.m_width;

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(repaint()));
    m_timer->start(1);
}

ScreenSaver::ScreenSaver(ScreenSaver &&other) :
    QGLWidget(other.parentWidget())
{
    this->m_dx = std::move(other.m_dx);
    this->m_dy = std::move(other.m_dy);
    this->m_dphi = std::move(other.m_dphi);
    this->m_x = std::move(other.m_x);
    this->m_y = std::move(other.m_y);
    this->m_phi = std::move(other.m_phi);
    this->m_height = std::move(other.m_height);
    this->m_width = std::move(other.m_width);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(repaint()));
    m_timer->start(1);
}

ScreenSaver &ScreenSaver::operator =(const ScreenSaver &other)
{
    setParent(other.parentWidget());

    this->m_dx = other.m_dx;
    this->m_dy = other.m_dy;
    this->m_dphi = other.m_dphi;
    this->m_x = other.m_x;
    this->m_y = other.m_y;
    this->m_phi = other.m_phi;
    this->m_height = other.m_height;
    this->m_width = other.m_width;

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(repaint()));
    m_timer->start(1);

    return *this;
}

ScreenSaver &ScreenSaver::operator =(ScreenSaver &&other)
{
    setParent(other.parentWidget());

    std::swap(this->m_dx, other.m_dx);
    std::swap(this->m_dy, other.m_dy);
    std::swap(this->m_dphi, other.m_dphi);
    std::swap(this->m_x, other.m_x);
    std::swap(this->m_y, other.m_y);
    std::swap(this->m_phi, other.m_phi);
    std::swap(this->m_height, other.m_height);
    std::swap(this->m_width, other.m_width);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(repaint()));
    m_timer->start(1);

    return *this;
}

ScreenSaver::~ScreenSaver()
{
    delete m_timer;
}

double ScreenSaver::getX() const
{
    return m_x;
}

double ScreenSaver::getY() const
{
    return m_y;
}

double ScreenSaver::getAngle() const
{
    return m_phi;
}

double ScreenSaver::getDX() const
{
    return m_dx;
}

double ScreenSaver::getDY() const
{
    return m_dy;
}

double ScreenSaver::getDAngle() const
{
    return m_dphi;
}

void ScreenSaver::setX(double x)
{
    m_x = x;
}

void ScreenSaver::setY(double y)
{
    m_y = y;
}

void ScreenSaver::setAngle(double phi)
{
    m_phi = phi;
}

void ScreenSaver::setDX(double dx)
{
    m_dx = dx;
}

void ScreenSaver::setDY(double dy)
{
    m_dy = dy;
}

void ScreenSaver::setDAngle(double dphi)
{
    m_dphi = dphi;
}

int ScreenSaver::getWidth() const
{
    return m_width;
}

int ScreenSaver::getHeight() const
{
    return m_height;
}

void ScreenSaver::setWidth(int w)
{
    m_width = w;
}

void ScreenSaver::setHeight(int h)
{
    m_height = h;
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

/*virtual*/ void ScreenSaver::mousePressEvent(QMouseEvent *event)
{
    m_dx = 0;
    m_dy = 0;
    prev_mouse_x = event->globalX();
    prev_mouse_y = event->globalY();
}

/*virtual*/ void ScreenSaver::mouseReleaseEvent(QMouseEvent *event)
{
    m_dx = (event->globalX() - prev_mouse_x) / 50;
    m_dy = (event->globalY() - prev_mouse_y) / 50;
}

void ScreenSaver::setPrevMouseX(double x)
{
    prev_mouse_x = x;
}

void ScreenSaver::setPrevMouseY(double y)
{
    prev_mouse_y = y;
}

double ScreenSaver::getPrevMouseX() const
{
    return prev_mouse_x;
}

double ScreenSaver::getPrevMouseY() const
{
    return prev_mouse_y;
}

/*virtual*/ void ScreenSaver::SlotMoveForward()
{
    if (m_x + m_dx > m_width || m_x + m_dx < 0)
        m_dx = -m_dx;
    m_x += m_dx;

    if (m_y + m_dy > m_height || m_y + m_dy < 0)
        m_dy = -m_dy;
    m_y += m_dy;

    if (m_phi + m_dphi > 4000 * M_PI)
        m_phi -= 2000 * M_PI;
    m_phi += m_dphi;
}

/*virtual*/ void ScreenSaver::SlotMoveBack()
{
    if (m_x - m_dx > m_width || m_x - m_dx < 0)
        m_dx = -m_dx;
    m_x -= m_dx;

    if (m_y - m_dy > m_height || m_y - m_dy < 0)
        m_dy = -m_dy;
    m_y -= m_dy;

    if (m_phi - m_dphi < 2 * M_PI)
        m_phi += 2000 * M_PI;
    m_phi -= m_dphi;
}

void ScreenSaver::repaint()
{
    //paintGL();
    update();
    SlotMoveForward();
}
