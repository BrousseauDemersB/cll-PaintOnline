#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QList>
#include <infopoint.h>
#include <QtNetwork/QTcpServer>
#include <thlisten.h>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QListWidget *Liste;//Liste des joueurs connectés.
    QPushButton *OnOff;//Permet d'activer ou de fermer le server.
    QTcpServer *Serveur;
    thListen *Listen;
    QList<InfoPoint> *ListePoints;//Liste des points affichés.
    QPainter Buffer;//Surface sur laquelle dessiner les points avant de les afficher dans la fenêtre.
    QPixmap Save;//Image dans laquelle sauvegarder la surface de dessin pour ne pas redessiner à chaque timertic.
    QTimer *Timer;
    int i;
protected:
    void paintEvent (QPaintEvent *);
private slots:
    void Ecoute();//Permet de traiter les nouvelles connexions de Serveur.
    void Update();
};

#endif // MAINWINDOW_H
