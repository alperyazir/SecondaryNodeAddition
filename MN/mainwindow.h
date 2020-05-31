#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "tcpserver.h"
#include "message.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum TIMESTAMPCOLOR{
   GREEN, // Incoming message color
    BLUE, // Status color
    RED,  // Error Color
    ORANGE // Sending mesaj color
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString get_time_stamp(TIMESTAMPCOLOR color = BLUE);
    void check_sna_is_startable();


private:
    Ui::MainWindow *ui;
    TcpServer *tcpServer;
    bool is_sn_connected{false};
    bool is_ue_connected{false};
    void create_server(int port);
    int port_sn;
    int port_ue;

    QVector<TcpServer*> servers;
public slots:


private slots:
    void on_buttonStartSNA_clicked();
};
#endif // MAINWINDOW_H
