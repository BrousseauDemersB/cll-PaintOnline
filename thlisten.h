#ifndef THLISTEN_H
#define THLISTEN_H

#include <QTcpSocket>
#include <QThread>
#include <QList>
#include <infopoint.h>

class thListen : public QThread
{
    Q_OBJECT
public:
    explicit thListen(QObject *parent = 0);
    thListen(QTcpSocket*, QList<InfoPoint>*);//Creation d'un thread d'écoute avec la liste de point dans laquelle écrire.
    QTcpSocket *Socket;
    QList<InfoPoint> *Liste;//Liste de point dans laquelle écrire(fenêtre principale).

protected:
    void run();

private:
    char ReadByte();//Lire un byte dans le buffer de données entrantes.
    uint ReadUint();//Lire un uint dans le buffer de données entrantes.
    float ReadFloat();//Lire un float dans le buffer de données entrantes.
    double ReadDouble();//Lire un double dans le buffer de données entrantes.

signals:

public slots:

};

#endif // THLISTEN_H
