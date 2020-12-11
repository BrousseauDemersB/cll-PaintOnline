#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(1024, 768);//Initialisation de la taille de la fenêtre.
    Liste = new QListWidget(this);//Ajout de la liste de joueurs à la fenêtre.
    Liste->setGeometry(10, 618, 500, 150);//Positionnement et initialisation de la taille du la liste de joueurs.
    OnOff = new QPushButton("Marche", this);//Ajout du bouton de marche/arrêt du server.
    OnOff->move(920, 738);//Place le bouton dans le coin bas droit de la fenêtre.
    ListePoints = new QList<InfoPoint>();//Initialisation de la liste de points.
    Serveur = new QTcpServer();
    Listen = new thListen();
    connect(Serveur, SIGNAL(newConnection()), this, SLOT(Ecoute()));//conection du slot d'écoute au signal de newConnection du Server.
    Serveur->listen(QHostAddress::Any, 42345);//Met le server en écoute sur le port 42345 pour n'importe quel IP entrant.
    Save = QPixmap(800, 600);
    Save.fill(Qt::transparent);
    Timer = new QTimer(this);
    this->connect(Timer, SIGNAL(timeout()), this, SLOT(Update()));
    Timer->start(1);
    i=0;
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    Buffer.begin(&Save);
    Buffer.drawPoint(50 + i % 800, 40 + i / 800);
    Buffer.end();
    Buffer.begin(this);
    Buffer.drawPixmap(0, 0, Save);
    Buffer.end();
    i++;
}

void MainWindow::Ecoute()
{
    Serveur->nextPendingConnection();
}

void MainWindow::Update()
{
    update();
}
