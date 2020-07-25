#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    mTcpServer = new QTcpServer(this);
    mTcpServer->setMaxPendingConnections(1);//允许最大连接数
    connect(mTcpServer, SIGNAL(newConnection()), this, SLOT(tcpNewConnection()));

    mTcpServer->listen(QHostAddress::Any,1235);//监听 通过改变监听密码来使各个接收之间不发生冲突

    ui->label->setText("Disconnected:");//刚开始没有连接的时候
}

MainWindow2::~MainWindow2()
{
    delete ui;
}


void MainWindow2::tcpNewConnection()
{
    mSocket = mTcpServer->nextPendingConnection();
    if(mSocket)
    {



        connect(mSocket,SIGNAL(readyRead()),this,SLOT(tcpReadyRead()));
        connect(mSocket, SIGNAL(disconnected()),this,SLOT(tcpDisconnect()));
        ui->label->setText("Connected:"); //建立
    }

}


void MainWindow2::tcpReadyRead()
{

    ui->textEdit->append(mSocket->readAll());


}


void MainWindow2::tcpDisconnect()
{
    mSocket->deleteLater();
    mSocket = 0;
    ui->label->setText("Dsiconnected:");

}

void MainWindow2::on_pushButton_clicked()
{
     mSocket->write(ui->lineEdit->text().toLatin1());

}

void MainWindow2::on_pushButton_2_clicked()
{
      mSocket->write(ui->lineEdit_2->text().toLatin1());
}

void MainWindow2::on_pushButton_3_clicked()
{
     mSocket->write(ui->lineEdit_3->text().toLatin1());
}
