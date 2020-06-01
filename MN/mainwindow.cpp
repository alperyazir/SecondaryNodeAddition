#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    setWindowTitle("MN");

    port_sn = 6666;
    port_ue = 6626;
    ui->buttonStartSNA->setEnabled(false);


    create_server(port_sn);
    create_server(port_ue);


}

MainWindow::~MainWindow()
{
    delete ui;
    qDeleteAll(servers);
}

QString MainWindow::get_time_stamp(TIMESTAMPCOLOR color)
{
    QString ret;
    switch (color) {
    case GREEN:
        ret = "[<font color=#28fc03>" + QTime::currentTime().toString("hh:mm:ss:zzz")+ "</font>]:";
        break;
    case BLUE:
        ret = "[<font color=#03c2fc>" + QTime::currentTime().toString("hh:mm:ss:zzz")+ "</font>]:";
        break;
    case RED:
        ret = "[<font color=#fc0303>" + QTime::currentTime().toString("hh:mm:ss:zzz")+ "</font>]:";
        break;
    case ORANGE:
        ret = "[<font color=#fcb103>" + QTime::currentTime().toString("hh:mm:ss:zzz")+ "</font>]:";
        break;
    default:
        ret = QTime::currentTime().toString("hh:mm:ss:zzz");
        break;
    }

    return ret;
}

void MainWindow::check_sna_is_startable()
{
    if(is_sn_connected && is_ue_connected)
    {
        ui->buttonStartSNA->setEnabled(true);
        ui->textBrowser->append(get_time_stamp() + " Secondary Node Addition Procedure can be started now with the Button!");
    }
    else
        ui->buttonStartSNA->setEnabled(false);

}

void MainWindow::create_server(int port)
{

    tcpServer = new TcpServer(port);


    connect(tcpServer,&TcpServer::server_started,this,[this](bool isStarted,int p){
        if(p == port_sn)
        {
            if(isStarted)
            {
                ui->textBrowser->append(get_time_stamp() + " Server Started for SN Communication Port: " + QString::number(p));
                servers[0] = tcpServer;
            }
            else
                ui->textBrowser->append(get_time_stamp(RED) + " Failed to create server SN!!");
        }
        else if(p == port_ue)
        {
            if(isStarted)
            {
                ui->textBrowser->append(get_time_stamp() + " Server Started for UE Communication Port: " + QString::number(p));
                servers[1] = tcpServer;
            }
            else
                ui->textBrowser->append(get_time_stamp(RED) + " Failed to create server UE!!");
        }
    });

    connect(tcpServer,&TcpServer::client_connected,this,[this](int port){

        if(port == port_sn)
        {
            ui->textBrowser->append(get_time_stamp(GREEN) + " SN Client Connected at Port: " + QString::number(port));
            is_sn_connected = true;
        }
        else if(port == port_ue)
        {
            ui->textBrowser->append(get_time_stamp(GREEN) + " UE Client Connected at Port: " + QString::number(port));
            is_ue_connected = true;
        }
        check_sna_is_startable();
    });

    connect(tcpServer,&TcpServer::new_message,this,[this](QString msg){
        MESSAGE_TYPE type = Message::getMessageType(msg);

        if( type== SgNBAdditionalRequestAcknowledge_t)
        {
            // Object that deserilialized from json
            SgNBAdditionalRequestAcknowledge obj = Message::getSgNBAdditionalRequestAcknowledge(msg);

            ui->textBrowser->append(get_time_stamp(GREEN) + "SgNBAdditionalRequestAcknowledge Message: ");
            ui->textBrowser->append(msg);
            ui->textBrowser->append(get_time_stamp() + "Doing some stuff here ...");
            ui->textBrowser->append(get_time_stamp() + "Doing some other stuff here ...");
            RRCConnectionReconfiguration request;
            request.Message_Type = "RRCConnectionReconfiguration";

            QJsonDocument doc(request.toJson());
            ui->textBrowser->append(get_time_stamp(ORANGE) + "Sending RRCConnectionReconfiguration message ");
            ui->textBrowser->append(doc.toJson().constData());
            servers.at(1)->write_message(doc.toJson().constData());
        }

        else if(type  == RRCConnectionReconfigurationComplete_t)
        {
            // Object that deserilialized from json
            RRCConnectionReconfigurationComplete obj = Message::getRRCConnectionReconfigurationCompletee(msg);
            ui->textBrowser->append(get_time_stamp(GREEN) + "RRCConnectionReconfigurationComplete Message: ");
            ui->textBrowser->append(msg);

            SgNBReconfigurationComplete request;
            request.Message_Type = "SgNBReconfigurationComplete";
            // Add other informations for this request

            QJsonDocument doc(request.toJson());
            ui->textBrowser->append(get_time_stamp(ORANGE) + "Sending SgNBReconfigurationComplete message ");
            ui->textBrowser->append(doc.toJson().constData());
            servers.at(0)->write_message(doc.toJson().constData() );

            ui->textBrowser-> append("\n=============================================================");
        }
    });

    connect(tcpServer,&TcpServer::client_disconnect,this,[this](int port){
        qDebug() << "Disconnected!" << port;
        if(port == port_sn)
        {
            ui->textBrowser->append(get_time_stamp(RED)+ "SN is disconnected!");
            is_sn_connected = false;
        }
        else if(port == port_ue)
        {
            ui->textBrowser->append(get_time_stamp(RED)+ "UE is disconnected!");
            is_ue_connected = false;
        }
        check_sna_is_startable();

    });

    tcpServer->start_server();
    update();
}


void MainWindow::on_buttonStartSNA_clicked()
{

    SgNBAdditionalRequest request;
    request.Message_Type = "SgNBAdditionalRequest";
    QJsonDocument doc(request.toJson());
    servers.at(0)->write_message(doc.toJson().constData() );
    ui->textBrowser->append(get_time_stamp(ORANGE)+ "SgNBAdditionalRequest is sending to SN");
    ui->textBrowser->append("SgNBAdditionalRequest Message: ");
    ui->textBrowser->append(doc.toJson().constData());
}
