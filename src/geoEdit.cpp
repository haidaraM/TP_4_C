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

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------------- PUBLIC

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli

    Commande macommande("C cercle 125 15 20");

    Commande macommande2("R rectangle 10 10 25 -58");

    macommande.AjouterCercle();
    macommande2.AjouterRectangle();
    geoEdit.Afficher();

    return 0;
}
