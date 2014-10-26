#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QWidget>
#include <QTimer>
#include <QGLWidget>
#include <cmath>

#define SSAV_X_SPEED 3
#define SSAV_Y_SPEED 2
#define SSAV_ANGLE_SPEED 0.01

class ScreenSaver : public QGLWidget
{
    Q_OBJECT
public:
    explicit ScreenSaver(QWidget *parent = 0, int dx = SSAV_X_SPEED, int dy = SSAV_Y_SPEED, float dphi = SSAV_ANGLE_SPEED);
    virtual ~ScreenSaver();

    int getX() const;
    int getY() const;
    double getAngle() const;

    int getWidth() const;
    int getHeight() const;

private:
    int m_dx;
    int m_dy;
    double m_dphi;
    int m_x;
    int m_y;
    double m_phi;
    int m_height;
    int m_width;


    QTimer *m_timer;

    // TODO It is very bed, when data is protected
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

signals:
    void widthChanged(int);
    void heightChanged(int);

public slots:
    void SlotMoveForward();
    void SlotMoveBack();

    void repaint();

};

#endif // SCREENSAVER_H
