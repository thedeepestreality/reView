#include <QCoreApplication>
#include <myserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    MrServer mServer;

    if(!mServer.listen(QHostAddress("127.0.0.1"), 7777)){//QHostAddress::
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started!";
    }

    return a.exec();
}
