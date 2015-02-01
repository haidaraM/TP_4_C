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
#include "Forme.h"
#include "Modele.h"
#include "CmdAjout.h"
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
    vector <string> res = decoupe();
    return res[1];
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdSimple::Execute() {
    stringstream stream(commande);
    string type;
    getline(stream,type,' ');
    CODERETOUR resultat = ERR_SYNTAXE;

    if(type =="C")
    {
        CmdAjout cmd(commande);
        resultat = cmd.AjouterCercle();
    }
    else if (type =="PL")
    {
        CmdAjout cmd(commande);
        resultat= cmd.AjouterPolyligne();
    }
    else if(type =="L")
    {
        CmdAjout cmd(commande);
        resultat= cmd.AjouterLigne();
    }
    else if(type =="R")
    {
        CmdAjout cmd(commande);
        resultat= cmd.AjouterRectangle();
    }
    else if(type =="S")
    {
        CmdAjout cmd(commande);
        resultat = cmd.AjouterSelection();
    }

    return resultat;
}

CODERETOUR CmdSimple::UnExecute() {
    string nom = GetNom(); // Recuperation du nom de la forme
    Forme *f = geoEdit.GetForme(nom); // recuperation de la forme
#ifdef MAP
    cout <<"Addresse de l'objet recupére :"<<f<<endl;
#endif
    geoEdit.CasserLien(f); // casse les liens
    delete f;
    geoEdit.EraseForme(nom); // Suppression de la MAP
    return GOOD;

}
