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
    for (int i = 0; i < cmds.size(); ++i)
    {
        cmds[i]->UnExecute();
    }

}

CODERETOUR CmdLoad::Execute() {
    if(cmds.size() == 0)
    {
        vector<string> resultat = decoupe();
        if (resultat.size() != 2) {
            AfficherErreurCommande();
            return ERR_SYNTAXE;
        }
        else {
            string fileName = resultat[1];
            string courant;
            ifstream file(fileName);
            if (file.good())
            {
                while (getline(file, courant))
                {
                    //cout <<"'"<<courant<<"'"<<endl;
                    CmdSimple *cmd = new CmdSimple(courant);
                    cmd->Execute();
                    cmds.push_back(cmd);
                }
            }
            else {
                cerr << "Probleme fichier " << endl;
                return ERR_SYNTAXE;
            }
        }
    }
    else
    {
        for (int i = 0; i < cmds.size(); ++i)
        {
            cmds[i]->Execute();
        }
    }

}
