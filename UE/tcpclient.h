#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);
    void connectTo(const QString &hostname, int port);
    ~TcpClient();

    void write_message(QString msg);
signals:
    void is_connected(bool);
    void new_message(QString);
    void disconnected_socket();
private:
    QTcpSocket *tcpSocket;

private slots:
    void readSocket();
    void discardSocket();

};

#endif // TCPCLIENT_H
