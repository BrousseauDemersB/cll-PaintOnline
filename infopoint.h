#ifndef INFOPOINT_H
#define INFOPOINT_H
#include <QPoint>
#include <QColor>

struct InfoPoint
{
    QPoint Position;//Position du point dans le cadre graphique.
    QColor Couleur;//Couleur du point en rgb.
    uint Grosseur;//Taille du point(rayon).
};

#endif // INFOPOINT_H
