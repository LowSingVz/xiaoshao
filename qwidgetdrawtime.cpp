#include "qwidgetdrawtime.h"
#include <QPainter>
QwidgetDrawTime::QwidgetDrawTime(QWidget *parent) : QWidget(parent)
{

}


void QwidgetDrawTime::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    painter->drawLine(0,0,75,75);
    painter->drawRect(0,0,75,75);
}
