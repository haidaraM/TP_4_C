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

    for(unsigned int i =0; i<cmds.size(); i++)
    {
        delete cmds[i];
    }
    cmds.clear();

} //----- Fin de ~CmdLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdLoad::UnExecute(bool afficheMsg) {
    //desactivation des messages
    afficheMsg = false;
    for(unsigned int i =0; i<cmds.size(); i++)
    {
        cmds[i]->UnExecute(afficheMsg);
    }
    return GOOD;
}//----- Fin de UnExecute

CODERETOUR CmdLoad::Execute(bool afficheMsg)
// Algorithme : Lecture séquentielle du fichier en exécutant les commandes.
// Si erreur, annulation des commandes exécutées. Le fichier ne sera lue
// qu'une seule fois.
{
    //desactivation des messages d'ajout
    afficheMsg = false;
    if(cmds.empty()) // s'il n'ya pas de commandes déjà enregistrée
    {
        vector<string> resultat = decoupe();
        CODERETOUR resCmd = GOOD;
        if (resultat.size() != 2) {
            AfficherErreurCommande();
            return ERR_SYNTAXE;
        }
        else {
            string fileName = resultat[1];
            string ligne;
            int nbFormes = 0;
            ifstream file(fileName);
            if (file.good()) {
                while (std::getline(file, ligne))
                {
                    // on ignore les commentaires
                    if(ligne[0] !='#')
                    {
                        CmdAjout *cmd = new CmdAjout(ligne);
                        resCmd = cmd->Execute(afficheMsg); // execution
                        if (resCmd != GOOD) {
                            /* Si une commande échoue on annule toutes les commandes et
                     on arrete la lecture du fichier*/
                            UnExecute(afficheMsg);
                            delete cmd;
                            return ERR_READING_FILE;
                        }
                        nbFormes++;
                        cmds.push_back(cmd); // ajout dans la pile
                    }
                }
#ifdef VERBOSE
        afficherConfirmation(fileName,nbFormes);
#endif
                return resCmd;
            }
            else {
#ifdef VERBOSE
            cerr <<ERREUR<<endl;
            cerr << COMMENTAIRES<<"Probleme de lecture du fichier "<<fileName << endl;
#endif
                return ERR_FILE;
            }
        } // fin else arguments valides
    } // fin if empty
    else
    {
        reExecute();
        return GOOD;
    }
}//----- Fin de Execute

void CmdLoad::afficherConfirmation(string file,int nbFormes) const {
    cout<<OK<<endl;
    cout<<COMMENTAIRES<<"Fichier "<<file<< " ajouté avec " <<nbFormes<< " Forme(s). "<<endl;
}

void CmdLoad::reExecute() {
    for(unsigned int i =0; i<cmds.size(); i++)
    {
        cmds[i]->Execute(false);
    }
}
