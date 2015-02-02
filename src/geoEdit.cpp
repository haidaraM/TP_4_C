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
#include "CmdLoad.h"
#include "CmdSave.h"
#include "CmdDelete.h"
#include "CmdMove.h"
#include "CmdClear.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

int main()
{
    Modele & geoEdit = Modele::Instance(); // Instance principale de l'appli
    string ligneCourante; // chaine representant la commande courante

    do{
        // recuperation de la ligne
        getline(cin, ligneCourante, '\n');

        // recuperation du type de la Commande
        size_t pos = ligneCourante.find(' ');
        string type = ligneCourante.substr(0, pos);

        // Commande d'ajout de Forme
        if(type == "C" || type =="PL" || type =="R" || type =="L")
        {
            CmdSimple *cmd = new CmdSimple(ligneCourante);
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
        // Ajout d'une Selection : la commande de création de la selection n'est pas UNDOABLE
        else if(type=="S")
        {
            CmdSimple cmd(ligneCourante);
            cmd.Execute();
        }
        // Deplacement d'un objet
        else if(type =="MOVE")
        {
            CmdMove *cmd = new CmdMove(ligneCourante);
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
        // Affichage des Forme
        else if(type =="LIST")
        {
            geoEdit.Afficher();
        }
        // Annulation de la derniere commande
        else if(type =="UNDO")
        {
            geoEdit.Undo();
        }
        // execution de la derniere commande annulée
        else if(type =="REDO")
        {
            geoEdit.Redo();
        }
        // Chargement d'un fichier
        else if(type =="LOAD")
        {
            CmdLoad *cmd = new CmdLoad(ligneCourante);
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
            CmdSave save(ligneCourante);
            save.Execute();
        }
        // Suppression de Forme
        else if(type=="DELETE")
        {
            CmdDelete *cmd = new CmdDelete(ligneCourante);
            if(cmd->Execute() == GOOD)
            {
                geoEdit.Empiler(cmd);
            }
            else
            {
                delete cmd;
            }
        }
        // suppression de toutes les formes
        else if(type =="CLEAR")
        {
            CmdClear *cmd = new CmdClear(ligneCourante);
            cmd->Execute();
            geoEdit.Empiler(cmd);
        }

    }while (ligneCourante != "EXIT");

    return 0;
}
