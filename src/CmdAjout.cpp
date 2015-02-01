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

//#define MAP //Pour la mise au Point

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



CODERETOUR CmdAjout::AjouterCercle(bool afficheMsg) {
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

        // Verification de la présence d'une autre Forme ayant le meme nom
        if(!geoEdit.FormeExiste(name))
        {
            Cercle *c = new Cercle(name,rayon, abscisse, ordonnee);
#ifdef MAP
            cout<<"Addresse de l'objet cree : "<<c<<endl;
#endif

            // Ajout à la MAP
            geoEdit.Ajouter(name, c);
#ifdef VERBOSE
        if(afficheMsg)
            afficheConfirmation("Cercle",name);
#endif
            return GOOD;
        }
        else
        {
#ifdef VERBOSE
            cerr<<ERREUR<<endl;
            cerr<<COMMENTAIRES<<"Une Forme avec le nom \""<<name<<"\" existe déjà."<<endl;
#endif
            return ERR_NAME_EXISTS;
        }
    }
}//----- Fin de AjouterCercle

CODERETOUR CmdAjout::AjouterPolyligne(bool afficheMsg) {
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

        // Verification de la présence d'une autre Forme ayant le meme nom
        if(!geoEdit.FormeExiste(name))
        {
            Polyligne * pl = new Polyligne(name, lesPoints);
#ifdef MAP
            cout<<"Addresse de l'objet cree : "<<pl<<endl;
#endif

            // Ajout à la MAP
            geoEdit.Ajouter(name, pl);
#ifdef VERBOSE
        if(afficheMsg)
            afficheConfirmation("Polyligne",name);
#endif
            return GOOD;
        }
        else
        {
#ifdef VERBOSE
            cerr<<ERREUR<<endl;
            cerr<<COMMENTAIRES<<"Une Forme avec le nom \""<<name<<"\" existe déjà."<<endl;
#endif
            return ERR_NAME_EXISTS;
        }
    }
}//----- Fin de AjouterPolyligne

CODERETOUR CmdAjout::AjouterRectangle(bool afficheMsg) {
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

        // Verification de la présence d'une autre Forme ayant le meme nom
        if(!geoEdit.FormeExiste(name))
        {
            Rectangle *r = new Rectangle(name,lesPoints);
#ifdef MAP
            cout<<"Addresse de l'objet cree : "<<r<<endl;
#endif
            // Ajout à la MAP
            geoEdit.Ajouter(name, r);
#ifdef VERBOSE
        if(afficheMsg)
            afficheConfirmation("Rectangle",name);
#endif
            return GOOD;
        }
        else
        {
#ifdef VERBOSE
            cerr<<ERREUR<<endl;
            cerr<<COMMENTAIRES<<"Une Forme avec le nom \""<<name<<"\" existe déjà."<<endl;
#endif
            return ERR_NAME_EXISTS;
        }

    }
}//----- Fin de AjouterRectangle

CODERETOUR CmdAjout::AjouterLigne(bool afficheMsg) {
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

        // Verification de la présence d'une autre Forme ayant le meme nom
        if(!geoEdit.FormeExiste(name))
        {
            Ligne *ligne = new Ligne(name,lesPoints);
#ifdef MAP
            cout<<"Addresse de l'objet cree : "<<ligne<<endl;
#endif
            // Ajout à la MAP
            geoEdit.Ajouter(name, ligne);
#ifdef VERBOSE
        if(afficheMsg)
            afficheConfirmation("Ligne",name);
#endif
            return GOOD;
        }
        else
        {
#ifdef VERBOSE
            cerr<<ERREUR<<endl;
            cerr<<COMMENTAIRES<<"Une Forme avec le nom \""<<name<<"\" existe déjà."<<endl;
#endif
            return ERR_NAME_EXISTS;
        }
    }
}//----- Fin de AjouterLigne

CODERETOUR CmdAjout::AjouterSelection(bool afficheMsg) {
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

        // Verification de la présence d'une autre Forme ayant le meme nom
        if(!geoEdit.FormeExiste(name))
        {
            // Recuperation des Formes qui se trouvent dans la selection
            vector<Forme *> formesSelectionnes = geoEdit.GetFormeSelection(p1, p2);

            // creation de la selection
            Selection *sc = new Selection(name, formesSelectionnes);

            geoEdit.Ajouter(name, sc);
#ifdef VERBOSE
            afficheConfirmation("Selection",name);
            cout <<COMMENTAIRES<<"Nombre d'objets dans la selection : "<<formesSelectionnes.size()<<endl;
#endif
            return GOOD;
        }
        else
        {
#ifdef VERBOSE
            cerr<<ERREUR<<endl;
            cerr<<COMMENTAIRES<<"Une Forme avec le nom \""<<name<<"\" existe déjà."<<endl;
#endif
            return ERR_NAME_EXISTS;
        }
    }
}//----- Fin de AjouterSelection

void CmdAjout::afficheConfirmation(string type, string nom) const {
    cout <<OK<<endl;
    cout <<COMMENTAIRES<<"Nouvelle Objet => "<<type<<" : "<<nom<<endl;
}
