#include <QDebug>
#include <iostream>
#include <QStringList>

#include <QHostAddress>
#include <QTest>

#include "yopt.h"

using namespace std;

Yopt::Yopt(int &argc,char** argv):QCoreApplication(argc,argv)
{
    //sock.connectToHost(QHostAddress("127.0.0.1"), 7777);
    connect(&sock,SIGNAL(bytesWritten(qint64)),this,SLOT(bye(qint64)));
}

void Yopt::write(QString s)
{
    sock.connectToHost(QHostAddress("127.0.0.1"), 7777);

    cout<<"Content-type: text/html; charset=utf-8\n\n";
    cout<<"Written: "<<sock.write(s.toAscii())<<"<p>";
}

void Yopt::bye(qint64 n)
{
    cout<<"bye! "<<n;
    this->exit();
}

int main(int argc, char** argv)
{



    //QCoreApplication a(argc,argv);
    Yopt yopt(argc,argv);

    //yopt.a=QCoreApplication(argc,argv);
    char query[1024];
    cin>>query;
    QString str(query);
    QStringList str_list=str.split("&");
    str_list=str_list.at(0).split("=");

    yopt.write(str_list.at(1));


    return yopt.exec();//
   // return a.exec();
}
