#include "thlisten.h"

thListen::thListen(QObject *parent) :
    QThread(parent)
{
}

thListen::thListen(QTcpSocket *S, QList<InfoPoint> *L)
{
    Socket = S;
    Liste = L;
}

void thListen::run()
{
    while (true)
    {
        while (Socket->bytesAvailable() > 0)
            ReadByte();
    }
}

char thListen::ReadByte()
{
    return Socket->read(1)[0];
}

uint thListen::ReadUint()
{
    return Socket->read(4).toUInt();
}

float thListen::ReadFloat()
{
    return Socket->read(4).toFloat();
}

double thListen::ReadDouble()
{
    return Socket->read(8).toDouble();
}
