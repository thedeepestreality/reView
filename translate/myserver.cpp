#include "myserver.h"

void MrServer::incomingConnection(int socketfd) {

    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);


    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void MrServer::disconnected() {
    QTcpSocket *client = (QTcpSocket*) sender();

    qDebug() << " INFO : " << QDateTime::currentDateTime()
            << " : CLIENT DISCONNECTED " << client->peerAddress().toString();
}

void MrServer::readyRead() {
    qDebug()<<"Yo! ";
    QTcpSocket *client = (QTcpSocket*) sender();
    QString s(client->readAll());
    double n=s.toDouble();
    qDebug()<<n;
    /*
    while (client->canReadLine()) {
              //here i needed a string..
        QString line = QString::fromUtf8(client->readLine()).trimmed();
         qDebug()<<line;

    }*/

}


/*
MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    mrServer = new MrServer(this);
    //socket=new QTcpSocket();
    connect(mrServer, SIGNAL(newConnection()), this, SLOT(serveNewConnection()));
   // connect(mrServer,SIGNAL())


    if(!mrServer->listen(QHostAddress("127.0.0.1"), 7777)){//QHostAddress::
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started!";
    }
}

void MyServer::serveNewConnection(){


    //QTcpSocket *socket1 = this->nextPendingConnection();
   // delete socket;
    socket =mrServer->nextPendingConnection();

    qDebug()<<"new cnnection! "<<socket->socketDescriptor();
    //this->
   // socket->open(QTcpSocket::ReadOnly);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readParams()));
    //QByteArray arr=socket->read
   // QString str(arr);
    //qDebug()<<str.size()<<" "<<str;

/*
    QTextStream os(socket);
    os.setAutoDetectUnicode(true);
    os << "HTTP/1.1 200 OK\r\n"
          "Content-Type: multipart/x-mixed-replace;boundary=b\r\n"
          "Cache-Control: no-store\r\n"
          "Pragma: no-cache\r\n"
          "Connection: close\r\n"
          "\r\n";

    QTimer *mrTimer = new QTimer(this);
    connect(mrTimer, SIGNAL(timeout()), this, SLOT(serveFurtherConnection()));
    mrTimer->start(30);
*/

/*
}

void MyServer::readParams()
{
    qDebug()<<"Got somethin'";
   // mrServer->i
}

/*
void MyServer::serveFurtherConnection(){

    QTime time;
    time.start();
    qDebug()<<"Started! "<<time.elapsed()<<"\n";
    *cap >> src;
    //usleep(30);
    qDebug()<<"Captured! "<<time.elapsed()<<"\n";
    std::vector<unsigned char> buffer;
    std::vector<int> param(2);
    param[0]=CV_IMWRITE_JPEG_QUALITY;
    param[1]=40;
    imencode(".jpg",src,buffer,param);
    qDebug()<<"Encoded! "<<time.elapsed()<<"\n";
   // qDebug() << buffer.size();

    char *new_buffer=new char[buffer.size()];
    int i;
    for (i=0; i<buffer.size(); i++){
        new_buffer[i] = buffer[i];
    }

    QTextStream os(socket);
    os.setAutoDetectUnicode(true);
    os <<"--b\r\n"
         "Content-Type: image/jpeg\r\n"
         "\r\n";
    //qDebug()<<"Ready to go! "<<time.elapsed()<<"\n";
    socket->write(new_buffer, i);
    //qDebug()<<"Wrote! "<<time.elapsed()<<"\n";
    //socket->flush();
}*/
