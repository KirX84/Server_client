#include "server.h"
#include "ui_server.h"
#include <QBuffer>

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    server = new myServer;
    connect(server, &myServer::data_to_send, this, &Server::date_received);
}



void Server:: date_received(QByteArray data)
{
    QPixmap p;
    if(p.loadFromData(data,"PNG"))
    {
        ui->ImageView->setPixmap(p);
        qDebug() << "received";
    }
}

Server::~Server()
{
    delete ui;
}

