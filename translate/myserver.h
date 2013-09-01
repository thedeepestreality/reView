#ifndef MYSERVER_H
#define MYSERVER_H

//#include <unistd.h>

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>
#include <QTextStream>
#include <QDateTime>
#include <QtTest/QTest>
#include <QByteArray>
#include <QTimer>



class MrServer : public QTcpServer
{
    Q_OBJECT
private slots:
    void readyRead();
    void disconnected();
protected:
    void incomingConnection(int);
};

/*
class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

signals:
    
public slots:
    void serveNewConnection();
    void readParams();
private:
    MrServer *mrServer;
    QTcpSocket *socket;
};*/

#endif // MYSERVER_H
