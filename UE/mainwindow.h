#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "tcpclient.h"
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


    QString get_time_stamp(TIMESTAMPCOLOR color=BLUE);
private slots:
    void on_buttonConnect_clicked();


private:
    Ui::MainWindow *ui;
    TcpClient *tcpClient = nullptr;

};
#endif // MAINWINDOW_H
