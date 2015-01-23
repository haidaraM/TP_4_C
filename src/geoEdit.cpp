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
#include "CmdAjoutCercle.h"

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------------- PUBLIC

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli

    CmdAjoutCercle macommande("C haidara 12 15 20");
    CmdAjoutCercle macommande2("C emilien -152 98 45");

    macommande.Execute();
    macommande2.Execute();
    cout<<endl;
    geoEdit.Afficher();

    return 0;
}
