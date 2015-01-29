/*************************************************************************
                           CmdLoad  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CmdLoad> (fichier CmdLoad.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "CmdLoad.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CmdLoad::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


CmdLoad::CmdLoad (string name ):Commande(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de CmdLoad


CmdLoad::~CmdLoad ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdLoad>" << endl;
#endif
} //----- Fin de ~CmdLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdLoad::UnExecute() {
   while(!cmds.empty())
   {
       cmds.top()->UnExecute();
       delete cmds.top();
       cmds.pop();
   }

}

CODERETOUR CmdLoad::Execute()
{
        vector<string> resultat = decoupe();
        CODERETOUR resCmd = GOOD;
        if (resultat.size() != 2)
        {
            AfficherErreurCommande();
            return ERR_SYNTAXE;
        }
        else
        {
            string fileName = resultat[1];
            string ligne;
            ifstream file(fileName);
            if (file.good())
            {
                while(std::getline(file, ligne) && resCmd == GOOD)
                {
                    CmdSimple * cmd = new CmdSimple(ligne);
                    resCmd = cmd->Execute(); // execution
                    cmds.push(cmd); // ajout dans la pile
                    if(resCmd != GOOD)
                    {
                        /* Si une commande échoue on annule toutes les commandes et
                         on arrete la lecture du fichier*/
                        UnExecute();
                    }
                }

                return resCmd;
            }
            else
            {
                cerr << "Probleme fichier " << endl;
                return ERR_FILE;
            }
        }
}
