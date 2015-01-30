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
//------------------------------------------------------ Include personnel

#include "Modele.h"
#include "CmdLoad.h"
#include "CmdSave.h"
#include "CmdSuppression.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli
    string courant; // chaine representant la commande courante

    do{
        // recuperation de la ligne
        getline(cin, courant, '\n');

        // recuperation du type de la Commande
        size_t pos = courant.find(' ');
        string type = courant.substr(0, pos);

        // Commande d'ajout de Forme
        if(type == "C" || type =="PL" || type =="R" || type =="L")
        {
            CmdSimple *cmd = new CmdSimple(courant);
            CODERETOUR resCmd = cmd->Execute();
            if(resCmd == GOOD)
            {
                geoEdit.Empiler(cmd);
            }
            else
            {
                delete cmd;
            }
        }
        else if(type =="S")
        {
            CmdSimple cmd(courant);
            cmd.Execute();
        }
        // Affichage de Forme
        else if(type =="LIST")
        {
            geoEdit.Afficher();
        }
        // Annulation de la derniere commande
        else if(type =="UNDO")
        {
            geoEdit.UNDO();
        }
        // execution de la derniere commande annulée
        else if(type =="REDO")
        {
            geoEdit.REDO();
        }
        // Chargement d'un fichier
        else if(type =="LOAD")
        {
            CmdLoad *cmd = new CmdLoad(courant);
            if(cmd->Execute() ==GOOD)
            {
                geoEdit.Empiler(cmd);
            }
            else
            {   // liberation de la memoire
                delete cmd;
            }
        }
        // Sauvegarde du Modele
        else if(type =="SAVE")
        {
            CmdSave save(courant);
            save.Execute();
        }
        // Suppression de Forme
        else if(type=="DELETE")
        {
            CmdSuppression cmd(courant);
            cmd.Execute();
        }

    }while (courant != "EXIT");

    return 0;
}
