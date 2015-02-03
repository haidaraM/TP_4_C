/*************************************************************************
                           CmdSave  -  description
                             -------------------
    début                : 26/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <CmdSave> (fichier CmdSave.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "CmdSave.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CmdSave::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


CmdSave::CmdSave (string name ):CmdSimple(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSave>" << endl;
#endif
} //----- Fin de CmdSave


CmdSave::~CmdSave ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSave>" << endl;
#endif
} //----- Fin de ~CmdSave


CODERETOUR CmdSave::Execute(bool afficheMsg) {
    // découpage de la commande
    vector<string> resultat = decoupe();

    if(resultat.size() != 2)
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        ofstream file(resultat[1].c_str());
        if(file.good())
        {
            geoEdit.Sauvegarder(file);

#ifdef VERBOSE
        cout<<OK<<endl;
#endif
            return GOOD;
        }
        else
            return ERR_FILE;
    }
}//----- Fin de Execute

CODERETOUR CmdSave::UnExecute(bool afficheMsg) {
    return GOOD;
}
