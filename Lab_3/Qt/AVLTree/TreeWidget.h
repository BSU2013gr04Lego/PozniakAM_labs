#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QSize>
#include <QPainter>
#include <QPaintEvent>
#include <math.h>
#include "AVLTree.h"

#ifndef WIDTH
#define WIDTH 80
#define HEIGHT 60
#endif

class TreeWidget : public QWidget
{
    Q_OBJECT
    AVLTree m_tree;

public:
    explicit TreeWidget(QWidget *parent = 0);
    ~TreeWidget();

    QSize sizeHint() const;
    QSize minimumSize() const;
    QSize maximumSize() const;

protected:
    void paintEvent(QPaintEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);

};

#endif // TREEWIDGET_H
