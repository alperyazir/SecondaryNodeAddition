#include "tcpclient.h"



TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::readyRead,this, &TcpClient::readSocket);
    connect(tcpSocket,&QTcpSocket::disconnected,this,&TcpClient::discardSocket);
}

void TcpClient::connectTo(const QString &hostname, int port)
{
    tcpSocket->connectToHost(hostname,port);

    if(!tcpSocket->waitForConnected())
    {
        qDebug() << "Connection Failed!";
        emit is_connected(false);
    }
    else
    {
        qDebug() << "Connected!";
        emit is_connected(true);
    }
}

TcpClient::~TcpClient()
{
    if(tcpSocket->isOpen())
        tcpSocket->close();

    delete tcpSocket;
}

void TcpClient::readSocket()
{
    QByteArray block = tcpSocket->readAll();

    QDataStream in(&block, QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        QString receiveString;
        in >> receiveString;
        receiveString.prepend(QString("%1 :: ").arg(tcpSocket->socketDescriptor()));
        emit new_message(receiveString);
    }
}

void TcpClient::discardSocket()
{
    tcpSocket->deleteLater();
    tcpSocket=nullptr;
    emit disconnect();
}

void TcpClient::write_message(QString msg)
{
    if(tcpSocket)
    {
        if(tcpSocket->isOpen())
        {

            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);

            out << msg;

            tcpSocket->write(block);
        }
    }
}
