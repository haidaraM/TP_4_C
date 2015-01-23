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

    CmdAjoutCercle macommande("C c11 12 15 20");
    macommande.Execute();
    cout<<endl;
    return 0;
}
