#ifndef YOPT_H
#define YOPT_H

#include <QTcpSocket>
#include <QCoreApplication>

class Yopt : public QCoreApplication
{
    Q_OBJECT
public:

    Yopt(int &argc,char** argv);
    QTcpSocket sock;
    void write(QString s);
public slots:
    void bye(qint64);
};

#endif // YOPT_H
