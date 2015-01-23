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

    Commande macommande("C haidara 125 15 20");
    Commande macommande2("C emilien -152- -98 45");

    macommande.AjouterCercle();
    macommande2.AjouterCercle();
    cout<<endl;
    geoEdit.Afficher();

    return 0;
}
