/*************************************************************************
                    CmdSimple  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CmdSimple> (fichier CmdSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "CmdSimple.h"
#include "CmdAjoutCercle.h"
#include "Forme.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


CmdSimple::CmdSimple (string name ):Commande(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSimple>" << endl;
#endif
} //----- Fin de CmdSimple


CmdSimple::~CmdSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSimple>" << endl;
#endif
} //----- Fin de ~CmdSimple

string CmdSimple::GetNom() const
{
    return commande.substr(2, commande.find(' ', 2)-2);
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdSimple::Execute() {
    stringstream stream(commande);
    string type;
    getline(stream,type,' ');

    if(type =="C")
    {
        CmdSimple *cmd = new CmdAjoutCercle(commande);
        cmd->Execute();
    }

}

CODERETOUR CmdSimple::UnExecute() {
    string nom = GetNom();
    Forme *f = geoEdit.getForme(nom);
    delete f;
    geoEdit.EraseForme(nom);
    return GOOD;

}
