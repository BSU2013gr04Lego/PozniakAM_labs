#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>

#define RADIUS 20
#define X_POS 0 //px from top left angle
#define Y_POS 0 //px

#define X_SPEED 5 //px
#define Y_SPEED 8 //px

#define DELAY 20 //ms

#define DEFAULT_WIDTH 640
#define DEFAULT_HEIGHT 480

class ScreenSaver : public QWidget
{
    Q_OBJECT

    double x, y, r;
    double dx, dy;
    int width, height;
    int delay;
    QTimer timer;
public:
    explicit ScreenSaver(QWidget *parent = 0);
    // deafult destructor
    // default copy ctor
    // default copy ass

    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:

};

#endif // SCREENSAVER_H
