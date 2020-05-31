#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>


class TcpServer: public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(int port,QObject *parent = 0);
    ~TcpServer();
    void start_server();
    void write_message(const QString &);

    int getPort() const;

public slots:
    void onNewConnection();
    void readSocket();
private:
    int port;
    QTcpServer *server;
    QTcpSocket *socket;
signals:
    void server_started(bool,int);
    void client_connected(int);
    void new_message(QString);
    void client_disconnect(int);
};

#endif // TCPSERVER_H
