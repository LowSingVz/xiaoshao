#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = nullptr);

signals:

};

#endif // MYTCPSOCKET_H
