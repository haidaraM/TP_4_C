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
#include <sstream>
#include "CmdAjoutCercle.h"
//------------------------------------------------------ Include personnel

#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli
    string courant; // chaine representant la commande courante
    Commande * cmd = NULL;
    do{
        getline(cin, courant, '\n'); // recuperation de la ligne
        size_t pos = courant.find(' ');
        string type = courant.substr(0, pos);// recuperation du type de commande
        if(type == "C")
        {
            cmd = new CmdAjoutCercle(courant);
            cmd->Execute();
        }
        else if(type == "PL")
        {
            //
        }
        else if(type =="LIST")
        {
            geoEdit.Afficher();
        }
        else if(type =="UNDO")
        {
            geoEdit.UNDO();
        }
        else if(type =="REDO")
        {
            geoEdit.REDO();
        }

    }while (courant != "EXIT");
    return 0;
}
