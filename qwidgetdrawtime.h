#ifndef QWIDGETDRAWTIME_H
#define QWIDGETDRAWTIME_H

#include <QWidget>

class QwidgetDrawTime : public QWidget
{
    Q_OBJECT
public:
    explicit QwidgetDrawTime(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

};

#endif // QWIDGETDRAWTIME_H
