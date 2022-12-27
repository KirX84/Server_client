#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QBuffer>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnImage_clicked()
{
    ui->ImageView->setPixmap(QPixmap(QFileDialog::getOpenFileName(0, "Открыть", "")));
}

void MainWindow::on_btnSend_clicked()
{
    socket->connectToHost(ui->IpEdit->text(), 5555);
    SendToServer();
}

void MainWindow::SendToServer()
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    QBuffer buffer(&Data);
    buffer.open(QIODevice::WriteOnly);
    ui->ImageView->pixmap()->save(&buffer, "PNG");
    qDebug() << Data.size() << "Client";
    socket -> write(Data);
}
