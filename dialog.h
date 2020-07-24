#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>

class Dialog : public QObject
{
    Q_OBJECT
public:
    explicit Dialog(QObject *parent = nullptr);

signals:

};

#endif // DIALOG_H
