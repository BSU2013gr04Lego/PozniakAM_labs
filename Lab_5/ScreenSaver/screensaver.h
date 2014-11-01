#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QWidget>
#include <QTimer>
#include <QGLWidget>
#include <QMouseEvent>
#include <cmath>

#define SSAV_X_SPEED 3.05
#define SSAV_Y_SPEED 1.77
#define SSAV_ANGLE_SPEED 0.01

class ScreenSaver : public QGLWidget
{
    Q_OBJECT
public:
    explicit ScreenSaver(QWidget *parent = 0, double dx = SSAV_X_SPEED, double dy = SSAV_Y_SPEED, double dphi = SSAV_ANGLE_SPEED);
    ScreenSaver(const ScreenSaver &other);
    ScreenSaver(ScreenSaver &&other);
    ScreenSaver& operator =(const ScreenSaver &other);
    ScreenSaver& operator =(ScreenSaver &&other);
    virtual ~ScreenSaver();

    double getX() const;
    double getY() const;
    double getAngle() const;
    double getDX() const;
    double getDY() const;
    double getDAngle() const;

    void setX(double x);
    void setY(double y);
    void setAngle(double phi);
    void setDX(double dx);
    void setDY(double dy);
    void setDAngle(double dphi);

    int getWidth() const;
    int getHeight() const;

    void setWidth(int w);
    void setHeight(int h);

private:
    double m_dx;
    double m_dy;
    double m_dphi;
    double m_x;
    double m_y;
    double m_phi;
    int m_height;
    int m_width;

    double prev_mouse_x;
    double prev_mouse_y;


    QTimer *m_timer;

    // TODO It is very bed, when data is protected
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL() = 0;

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    void setPrevMouseX(double x);
    void setPrevMouseY(double y);
    double getPrevMouseX() const;
    double getPrevMouseY() const;/*virtual*/ void ScreenSaver::paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        double x_offset = getX();
        double y_offset = getY();

        int n = 64;
        glPointSize(2);
        glBegin(GL_POLYGON);
            glColor3f(1, 1, 1);
            for (int i = 0; i < n; ++i)
            {
                double angle = 2 * 3.14 * i / n;
                double x = (cos(angle) * 40 + x_offset);
                double y = (sin(angle) * 40 + y_offset);
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

signals:
    void widthChanged(int);
    void heightChanged(int);

public slots:
    virtual void SlotMoveForward();
    virtual void SlotMoveBack();

    void repaint();

};

#endif // SCREENSAVER_H
