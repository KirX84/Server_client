#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QTcpSocket>


class myServer : public QTcpServer
{
    Q_OBJECT
public:

    myServer();
    QTcpSocket* socket;

private:
    void SendToClient();
    QByteArray Data;
    quint32 blockSize;

public slots:
    void incomingConnection(qintptr socketDescreptor);
    void slotReadyRead();
signals:
    void data_to_send(QByteArray);

};

#endif // MYSERVER_H
