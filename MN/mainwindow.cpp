#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "message.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->buttonStartSNA->setEnabled(false);
    port_sn = 6666;
    port_ue = 6626;
    create_server(port_sn);
    create_server(port_ue);



    SgNBAdditionalRequest m;
    m.Message_Type = "Alper";
    m.e_rab_request.pdcp_present_in_sn.Bearer_Type="comba";
    QJsonDocument doc(m.toJson());
    qDebug() << doc.toJson().constData();

    SgNBAdditionalRequest tr;
    tr = Message::getSgNBAdditionalRequest(doc.toJson().constData());
    qDebug()<< tr.Message_Type;
    qDebug() << tr.e_rab_request.pdcp_present_in_sn.Bearer_Type;

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::create_server(int port)
{

    tcpServer = new TcpServer(port);

    connect(tcpServer,&TcpServer::server_started,this,[this](bool isStarted,int p){
        if(p == port_sn)
        {
            if(isStarted)
                ui->textBrowser->append("Server Started for SN Communication Port: " + QString::number(p));
            else
                ui->textBrowser->append("Failed to create server SN!!");
        }
        else if(p == port_ue)
        {
            if(isStarted)
                ui->textBrowser->append("Server Started for UE Communication Port: " + QString::number(p));
            else
                ui->textBrowser->append("Failed to create server UE!!");
        }
    });

    connect(tcpServer,&TcpServer::client_connected,this,[this](int port){

        if(port == port_sn)
        {
            ui->textBrowser->append("SN Client Connected at Port: " + QString::number(port));
            is_sn_connected = true;
        }
        else if(port == port_ue)
        {
            ui->textBrowser->append("UE Client Connected at Port: " + QString::number(port));
            is_ue_connected = true;
        }

        if(is_sn_connected && is_ue_connected)
            ui->buttonStartSNA->setEnabled(true);


    });

    connect(tcpServer,&TcpServer::new_message,this,[this](QString msg){
        // ui->textBrowser->append("Message: "+ msg +  " at Port: " + QString::number(tcpServer->getPort()));
    });

    tcpServer->start_server();
    update();
}


void MainWindow::on_buttonStartSNA_clicked()
{

}
