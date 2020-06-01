#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("UE");
    tcpClient = new TcpClient;
    connect(tcpClient, &TcpClient::is_connected,this,[this](bool isConnected){
        if(isConnected)
            ui->textBrowser->append(get_time_stamp() + " Connected to: "+ ui->lineEditHostname->text());
        else
            ui->textBrowser->append(get_time_stamp(RED) + " Failed connected to: "+ ui->lineEditHostname->text());
    });

    connect(tcpClient, &TcpClient::new_message,this,[this](QString msg){
        MESSAGE_TYPE type = Message::getMessageType(msg);

        if(type == RRCConnectionReconfiguration_t)
        {
            ui->textBrowser->append(get_time_stamp(GREEN) + " RRCConnectionReconfiguration message:");
            ui->textBrowser->append(msg);
            RRCConnectionReconfiguration request = Message::getRRCConnectionReconfiguration(msg);

            /// TODO adding operations.
            ui->textBrowser->append(get_time_stamp() + " Doing some stuff in UE ...");
            ui->textBrowser->append(get_time_stamp() + " Doing some other stuff in UE ...");
            ui->textBrowser->append(get_time_stamp(ORANGE) + " Sending RRCConnectionReconfigurationComplete message:");
            ui->textBrowser->append(msg);

            RRCConnectionReconfigurationComplete obj;
            obj.Message_Type = "RRCConnectionReconfigurationComplete";

            QJsonDocument doc(obj.toJson());
            tcpClient->write_message(doc.toJson().constData() );

            ui->textBrowser-> append("\n=============================================================");
        }

    });
    connect(tcpClient, &TcpClient::disconnected_socket,this,[this](){
        ui->textBrowser->append(get_time_stamp(RED) + " Connection Lost");
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
