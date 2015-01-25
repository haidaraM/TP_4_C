/*************************************************************************
                           CmdAjoutCercle  -  description
                             -------------------
    début                : 16/05/2015
	copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <CmdAjoutCercle> (fichier CmdAjoutCercle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjoutCercle.h"
#include "Cercle.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
CmdAjoutCercle::CmdAjoutCercle (string cmd ):Commande(cmd)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutCercle>" << endl;
#endif
} //----- Fin de CmdAjoutCercle


CmdAjoutCercle::~CmdAjoutCercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutCercle>" << endl;
#endif
} //----- Fin de ~CmdAjoutCercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdAjoutCercle::Execute() {
    // découpage de la commande
    vector<string> resultat = decoupe();

    if(resultat.size() != 5 || !allDigit(resultat))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = resultat[1];
        long abscisse = strtol(resultat[2].c_str(), NULL, 10);
        long ordonnee = strtol(resultat[3].c_str(), NULL, 10);
        unsigned int rayon =(unsigned int) strtol(resultat[4].c_str(), NULL, 10);

        Cercle *c = new Cercle(name,rayon, abscisse, ordonnee);

        //Mise à jour de la Map
        if(!geoEdit.NomExiste(name))
        {
            geoEdit.Ajouter(name, c);
            // Empilement commande
            // penser à liberer la pile de redo
            geoEdit.Empiler(this);
            return GOOD;
        }
        else
            return ERR_NAME_EXISTS;
    }
}

CODERETOUR CmdAjoutCercle::UnExecute()
{
    string nom = GetNom();
    Forme *f = geoEdit.getForme(nom);
    delete f;
    geoEdit.EraseForme(nom);
    return GOOD;
}

string CmdAjoutCercle::GetNom() const
{
    return commande.substr(2, commande.find(' ', 2)-2);
}
