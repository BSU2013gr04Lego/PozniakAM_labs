#ifndef SS_BOOMERANG_H
#define SS_BOOMERANG_H

#include <screensaver.h>
#include <cmath>

class SS_boomerang : public ScreenSaver
{
    Q_OBJECT
public:
    explicit SS_boomerang(QWidget *parent = 0);
    ~SS_boomerang();

protected:
    virtual void paintGL();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
};

#endif // SS_BOOMERANG_H
