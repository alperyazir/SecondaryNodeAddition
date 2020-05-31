#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpClient = new TcpClient;
    connect(tcpClient, &TcpClient::is_connected,this,[this](bool isConnected){
        if(isConnected)
            ui->textBrowser->append("Connected to: "+ ui->lineEditHostname->text());
        else
            ui->textBrowser->append("Failed connected to: "+ ui->lineEditHostname->text());
    });

    connect(tcpClient, &TcpClient::new_message,this,[this](QString msg){
        ui->textBrowser->append(msg);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    tcpClient->connectTo(ui->lineEditHostname->text(),ui->lineEditPort->text().toInt());
}

