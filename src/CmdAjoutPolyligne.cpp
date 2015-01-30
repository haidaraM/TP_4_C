/*************************************************************************
                           CmdAjoutPoyligne  -  description
                             -------------------
    début                : 16/05/2015
	copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <CmdAjoutPoyligne> (fichier CmdAjoutPoyligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Modele.h"
#include "CmdAjoutPolyligne.h"
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
CmdAjoutPoyligne::CmdAjoutPoyligne (string cmd ):CmdSimple(cmd)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutPoyligne>" << endl;
#endif
} //----- Fin de CmdAjoutPoyligne


CmdAjoutPoyligne::~CmdAjoutPoyligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutPoyligne>" << endl;
#endif
} //----- Fin de ~CmdAjoutPoyligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdAjoutPoyligne::Execute() {
    // découpage de la commande
    vector<string> resultat = decoupe();

    // Minimum 2 points => min 6 arguments
    if(resultat.size() < 6 || !allDigit(resultat) ||
            resultat.size()%2 != 0)
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = resultat[1];
        vector<Point> lesPoints;
        for(unsigned int i = 2; i<resultat.size()-1; i=i+2)
        {
            long x1 = strtol(resultat[i].c_str(), NULL, 10);
            long y1 = strtol(resultat[i+1].c_str(), NULL, 10);
            lesPoints.push_back(Point(x1,y1));
        }

        Polyligne * pl = new Polyligne(name, lesPoints);

        if(!geoEdit.NomExiste(name))
        {
            geoEdit.Ajouter(name, pl);
            return GOOD;
        }
        else
            return ERR_NAME_EXISTS;
    }

}

