#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include "myserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private:
    Ui::Server *ui;
    myServer* server;

public slots:
    void date_received(QByteArray Data);
};
#endif // SERVER_H
