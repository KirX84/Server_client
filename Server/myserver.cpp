#include "myserver.h"
#include <QDataStream>

myServer::myServer()
{
    if (this->listen(QHostAddress::Any,5555))
    {
        qDebug()<<"Listening";
    }
    else
    {
        qDebug()<<"Not listening";
    }
}

void myServer::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead,this,&myServer::slotReadyRead);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    qDebug()<<socketDescriptor<<" Client connected";
}

void myServer::slotReadyRead()
{
    Data.clear();
    Data.append(socket ->readAll());
    for(;;)
    {
        if (socket->waitForReadyRead(5000))
            Data.append(socket->readAll());
        else
            break;
    }

    qDebug() << Data.size() << "Server";
    data_to_send(Data);


}
