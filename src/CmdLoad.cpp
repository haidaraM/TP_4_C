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

    while(!cmds.empty())
    {
        delete cmds.top();
        cmds.pop();
    }

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
    return GOOD;
}//----- Fin de UnExecute

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
        int nbFormes = 0;
        ifstream file(fileName);
        if (file.good())
        {
            while(std::getline(file, ligne))
            {
                nbFormes++;
                CmdAjout * cmd = new CmdAjout(ligne);
                resCmd = cmd->Execute(); // execution
                cmds.push(cmd); // ajout dans la pile
                if(resCmd != GOOD)
                {
                    /* Si une commande échoue on annule toutes les commandes et
                     on arrete la lecture du fichier*/
                    UnExecute();
                    return ERR_READING_FILE;
                }
            }

#ifdef VERBOSE
        afficherConfirmation(fileName,nbFormes);
#endif
            return resCmd;
        }
        else
        {
            cerr <<ERREUR<<endl;
            cerr << COMMENTAIRES<<"Probleme de lecture du fichier "<<fileName << endl;
            return ERR_FILE;
        }
    }
}//----- Fin de Execute

void CmdLoad::afficherConfirmation(string file,int nbFormes) const {
    cout<<"OK"<<endl;
    cout<<COMMENTAIRES<<"Fichier "<<file<< " ajouté avec " <<nbFormes<< " Forme(s) ajoutée(s) "<<endl;
}
