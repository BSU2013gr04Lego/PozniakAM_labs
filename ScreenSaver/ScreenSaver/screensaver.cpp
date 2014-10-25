#include "screensaver.h"

ScreenSaver::ScreenSaver(QWidget *parent) :
    QWidget(parent)
{
    x = X_POS;
    y = Y_POS;
    r = RADIUS;

    dx = X_SPEED;
    dy = Y_SPEED;

    width = DEFAULT_WIDTH;
    height = DEFAULT_HEIGHT;

    delay = DELAY;

    connect(&timer, SIGNAL(timeout()), SLOT(update()));

    timer.start(delay);
}

QSize ScreenSaver::sizeHint() const
{
    return (QSize(width, height));
}

void ScreenSaver::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.drawEllipse(x, y, r, r);

    if (x + dx > width)
        dx = - X_SPEED;
    if (x + dx < 0)
        dx = X_SPEED;
    if (y + dy > height)
        dy = - Y_SPEED;
    if (y + dy < 0)
        dy = Y_SPEED;
    x += dx;
    y += dy;
}

