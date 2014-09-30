#include "TreeWidget.h"


using namespace std;
//---------------- CONSTRUCTORS ----------------

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent)
{
    for (int i = 0; i < 40; ++i)
        m_tree.insert(i, i * 10);
}

//----------------/CONSTRUCTORS ----------------
//---------------- DESTRUCTORS -----------------

TreeWidget::~TreeWidget()
{
}

//----------------/DESTRUCTORS -----------------
//---------------- PUBLIC METHODS --------------

QSize TreeWidget::sizeHint() const
{
    return QSize(WIDTH * (m_tree.rootHeight() + 1) + 20, HEIGHT * pow(2, m_tree.rootHeight()) + 20);
}

QSize TreeWidget::minimumSize() const
{
    return QSize(WIDTH * (m_tree.rootHeight() + 1) + 20, HEIGHT * pow(2, m_tree.rootHeight()) + 20);
}

QSize TreeWidget::maximumSize() const
{
    return QSize(WIDTH * (m_tree.rootHeight() + 1) + 20, HEIGHT * pow(2, m_tree.rootHeight()) + 20);
}

//---------------- PUBLIC METHODS --------------
//---------------- PROTECTED METHODS -----------

void TreeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillRect(event->rect(), QBrush(Qt::white));

    m_tree.paintTree(&painter);

}

//---------------- PROTECTED METHODS -----------
