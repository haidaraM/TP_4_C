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
//------------------------------------------------------ Include personnel

#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli
    string courant; // commande courante
    do{
        getline(cin, courant, '\n');
        Commande cmd(courant);
        cmd.Execute();
    }while (courant != "EXIT");
    return 0;
}
