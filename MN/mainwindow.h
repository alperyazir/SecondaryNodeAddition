#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
enum PROCESS_TYPE{SN,UE};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TcpServer *tcpServer;
    bool is_sn_connected{false};
    bool is_ue_connected{false};
    void create_server(int port);
    int port_sn;
    int port_ue;
public slots:


private slots:
    void on_buttonStartSNA_clicked();
};
#endif // MAINWINDOW_H
