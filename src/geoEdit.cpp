/*************************************************************************
                           geoEdit  -  description
                             -------------------
    début                : ${16/01/2015}
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>
#include "Modele.h"
#include "Forme.h"

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------------- PUBLIC

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli

    Commande macommande("C cercle 125 15 20");
    Commande macommande2("R rectangle 10 10 25 -58");
    Commande macommande3("PL polyligne 1 2 3 4 5 6 7 8 6 78");
/*
    macommande.AjouterCercle();
    macommande2.AjouterRectangle();
    macommande3.AjouterPolyligne();
    geoEdit.Afficher(); */

    macommande3.Execute();

    geoEdit.Afficher();

    return 0;
}
