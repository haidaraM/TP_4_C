/*************************************************************************
                           CmdAjout  -  description
                             -------------------
    début                : 16/05/2015
	copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <CmdAjout> (fichier CmdAjout.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdAjout.h"
#include "Cercle.h"
#include "Modele.h"
#include "Polyligne.h"
#include "Rectangle.h"
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
CmdAjout::CmdAjout (string cmd ):CmdSimple(cmd)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjout>" << endl;
#endif
} //----- Fin de CmdAjout


CmdAjout::~CmdAjout ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjout>" << endl;
#endif
} //----- Fin de ~CmdAjout



CODERETOUR CmdAjout::AjouterCercle() {
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
            return GOOD;
        }
        else
            return ERR_NAME_EXISTS;
    }
}

CODERETOUR CmdAjout::AjouterPolyligne() {
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

CODERETOUR CmdAjout::AjouterRectangle() {
    // découpage de la commande
    vector<string> resultat = decoupe();

    if(resultat.size() != 6 || !allDigit(resultat))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = resultat[1];
        vector<Point> lesPoints;
        long x1 = strtol(resultat[2].c_str(), NULL, 10);
        long y1 = strtol(resultat[3].c_str(), NULL, 10);
        long x2 = strtol(resultat[4].c_str(), NULL, 10);
        long y2 = strtol(resultat[5].c_str(), NULL, 10);

        lesPoints.push_back(Point(x1,y1));
        lesPoints.push_back(Point(x2,y2));

        Rectangle *r = new Rectangle(name,lesPoints);

        //Mise à jour de la Map
        geoEdit.Ajouter(name, r);

        return GOOD;
    }
}

CODERETOUR CmdAjout::AjouterLigne() {
    // découpage de la commande
    vector<string> resultat = decoupe();

    if(resultat.size() != 6 || !allDigit(resultat))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = resultat[1];
        vector<Point> lesPoints;
        long x1 = strtol(resultat[2].c_str(), NULL, 10);
        long y1 = strtol(resultat[3].c_str(), NULL, 10);
        long x2 = strtol(resultat[4].c_str(), NULL, 10);
        long y2 = strtol(resultat[5].c_str(), NULL, 10);

        lesPoints.push_back(Point(x1,y1));
        lesPoints.push_back(Point(x2,y2));

        Ligne *ligne = new Ligne(name,lesPoints);

        //Mise à jour de la Map
        geoEdit.Ajouter(name, ligne);

        return GOOD;

    }
}
