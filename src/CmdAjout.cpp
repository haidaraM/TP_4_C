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
#include "Selection.h"

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
    vector<string> arguments = decoupe();

    if(arguments.size() != 5 || !allDigit(arguments))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = arguments[1];
        long abscisse = strtol(arguments[2].c_str(), NULL, 10);
        long ordonnee = strtol(arguments[3].c_str(), NULL, 10);
        unsigned int rayon =(unsigned int) strtol(arguments[4].c_str(), NULL, 10);

        Cercle *c = new Cercle(name,rayon, abscisse, ordonnee);

        //Mise à jour de la Map
        if(!geoEdit.FormeExiste(name))
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
    vector<string> arguments = decoupe();

    // Au moins un point => au minimum 4 arguments
    if(arguments.size() < 4 || !allDigit(arguments) || arguments.size()%2 != 0)
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = arguments[1];
        vector<Point> lesPoints;
        for(unsigned int i = 2; i<arguments.size()-1; i=i+2)
        {
            long x1 = strtol(arguments[i].c_str(), NULL, 10);
            long y1 = strtol(arguments[i+1].c_str(), NULL, 10);
            lesPoints.push_back(Point(x1,y1));
        }

        Polyligne * pl = new Polyligne(name, lesPoints);

        if(!geoEdit.FormeExiste(name))
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
    vector<string> arguments = decoupe();

    if(arguments.size() != 6 || !allDigit(arguments))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = arguments[1];
        vector<Point> lesPoints;
        long x1 = strtol(arguments[2].c_str(), NULL, 10);
        long y1 = strtol(arguments[3].c_str(), NULL, 10);
        long x2 = strtol(arguments[4].c_str(), NULL, 10);
        long y2 = strtol(arguments[5].c_str(), NULL, 10);

        lesPoints.push_back(Point(x1,y1));
        lesPoints.push_back(Point(x2,y2));

        Rectangle *r = new Rectangle(name,lesPoints);

        if(!geoEdit.FormeExiste(name))
        {
            geoEdit.Ajouter(name, r);
            return GOOD;
        }
        else
            return ERR_NAME_EXISTS;

    }
}

CODERETOUR CmdAjout::AjouterLigne() {
    // découpage de la commande
    vector<string> arguments = decoupe();

    if(arguments.size() != 6 || !allDigit(arguments))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = arguments[1];
        vector<Point> lesPoints;
        long x1 = strtol(arguments[2].c_str(), NULL, 10);
        long y1 = strtol(arguments[3].c_str(), NULL, 10);
        long x2 = strtol(arguments[4].c_str(), NULL, 10);
        long y2 = strtol(arguments[5].c_str(), NULL, 10);

        lesPoints.push_back(Point(x1,y1));
        lesPoints.push_back(Point(x2,y2));

        Ligne *ligne = new Ligne(name,lesPoints);

        if(!geoEdit.FormeExiste(name))
        {
            geoEdit.Ajouter(name, ligne);
            return GOOD;
        }
        else
            return ERR_NAME_EXISTS;
    }
}

CODERETOUR CmdAjout::AjouterSelection() {
    // decoupage de la commande
    vector<string> arguments = decoupe();
    if(arguments.size() != 6)
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Organisation des elements
        string name = arguments[1];
        long x1 = strtol(arguments[2].c_str(), NULL, 10);
        long y1 = strtol(arguments[3].c_str(), NULL, 10);
        long x2 = strtol(arguments[4].c_str(), NULL, 10);
        long y2 = strtol(arguments[5].c_str(), NULL, 10);

        Point p1(x1,y1);
        Point p2(x2,y2);

        vector<Forme *> formesSelectionnes = geoEdit.GetFormeSelection(p1, p2);

        cout <<"#Nombre d'objet dans la selection : "<<formesSelectionnes.size()<<endl;

        Selection *sc = new Selection(name, formesSelectionnes);

        if(!geoEdit.FormeExiste(name))
        {
            geoEdit.Ajouter(name, sc);
            return GOOD;
        }
        else
            return ERR_NAME_EXISTS;
    }
}
