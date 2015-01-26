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
#include "CmdLoad.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli
    string courant; // chaine representant la commande courante
    do{
        getline(cin, courant, '\n'); // recuperation de la ligne
        size_t pos = courant.find(' ');
        string type = courant.substr(0, pos);// recuperation du type de commande
        if(type == "C" || type =="PL" || type =="R")
        {
            CmdSimple *cmd = new CmdSimple(courant);
            if(cmd->Execute() ==GOOD )
            {
                geoEdit.Empiler(cmd);
            }
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
        else if(type =="LOAD")
        {
            CmdLoad *cmd = new CmdLoad(courant);
            if(cmd->Execute() ==GOOD)
            {
                geoEdit.Empiler(cmd);
            }
        }

    }while (courant != "EXIT");
    return 0;
}
