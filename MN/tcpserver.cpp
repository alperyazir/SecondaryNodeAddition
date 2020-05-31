#include "tcpserver.h"


TcpServer::TcpServer(int port, QObject *parent):
    QObject(parent),
    port(port)
{

}

TcpServer::~TcpServer()
{
///TODO
}

void TcpServer::start_server()
{
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);
    if(server->listen(QHostAddress::Any,port))
    {
        emit server_started(true,port);
        qDebug() << "Server is started at port: "+ QString::number(port);
    }
    else
    {
        emit server_started(false,port);
        qDebug() << "Failed to create server!";
    }
}

void TcpServer::write_message(QString msg)
{
    if(socket)
    {
        if(socket->isOpen())
        {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out << msg;
            socket->write(block);
        }
    }
}

void TcpServer::onNewConnection()
{
    socket = server->nextPendingConnection();
    connect(socket,&QTcpSocket::readyRead,this,&TcpServer::readSocket);
    emit client_connected(port);
}

void TcpServer::readSocket()
{
    QByteArray block = socket->readAll();

    QDataStream in(&block, QIODevice::ReadOnly);

    while (!in.atEnd())
    {
        QString receiveString;
        in >> receiveString;
        receiveString.prepend(QString("%1 :: ").arg(socket->socketDescriptor()));
        emit new_message(receiveString);
    }
}

int TcpServer::getPort() const
{
    return port;
}
