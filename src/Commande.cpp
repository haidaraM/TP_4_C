/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/
//---------- Réalisation de la classe <Commande> (fichier Commande.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include <sstream> // stringstream

#include "Rectangle.h"
#include "Commande.h"
#include "Modele.h"
#include "Cercle.h"
#include "Ligne.h"

//------------------------------------------------------------- Constantes
const string COMMENTAIRES("#");
const string CMD_PARAM_ERR("paramètres invalides");
const string ERREUR("ERR");

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

Modele & Commande::geoEdit = Modele::Instance();

Commande::Commande (string cmd ):commande(cmd)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Commande>" << endl;
#endif
} //----- Fin de Commande


Commande::~Commande ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Commande>" << endl;
#endif
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR Commande::AjouterCercle()
{
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
        geoEdit.Ajouter(name, c);
        // Empilement commande
        return GOOD;
    }
}

CODERETOUR Commande::AjouterRectangle() {
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

CODERETOUR Commande::AjouterPolyligne() {
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

        //Mise à jour de la Map
        geoEdit.Ajouter(name, pl);
        return GOOD;
    }


}

CODERETOUR Commande::AjouterSelection() {
    return GOOD;
}

bool Commande::allDigit(vector<string> vect, unsigned int pos)const {
    bool estNombre = true;
    unsigned int i = pos;
    while(estNombre && i<vect.size())
    {
        if(!isDigit(vect[i]))
            estNombre = false;
        i++;
    }
    return estNombre;
}

bool Commande::isDigit(string chaine) const
{
    bool estNombre = true;
    unsigned int i = 0;
    while(estNombre && i < chaine.length())
    {
        if(!isdigit(chaine[i]) && chaine[i] != '-' && chaine[i] !='+')
            estNombre = false;
        i++;
    }
    return estNombre;
}

vector<string> Commande::decoupe(char delim) const
{
    vector<string> resultat; // vecteur des elements de la ligne
    stringstream stream(commande); // conversion du string en string stream
    string courant; // element courant

    while(getline(stream, courant, delim))
    {
        //Ajout de l'element courant
        if(courant.size()!=0)
            resultat.push_back(courant);
    }

    return resultat;
}



CODERETOUR Commande::Deplacer() {
    return GOOD;
}

CODERETOUR Commande::Supprimer() {
    return GOOD;
}

CODERETOUR Commande::AjouterLigne()
{
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

CODERETOUR Commande::Sauvegarder()const
{
    // découpage de la commande
    vector<string> resultat = decoupe();

    if(resultat.size() != 2)
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        geoEdit.Sauvegarder(resultat[1]);
        return GOOD;
    }
}

CODERETOUR Commande::Execute()
{
    stringstream stream(commande);
    string commande;
    getline(stream,commande,' ');
    CODERETOUR res;
    if(commande == "C")
    {
        res=AjouterCercle();
        if(res)
        {
            geoEdit.Empiler(*this);
        }
    }
    else if(commande == "PL")
    {
        res = AjouterPolyligne();
        if(res)
        {
            geoEdit.Empiler(*this);
        }
    }
    else if(commande == "R")
    {
        res = AjouterRectangle();
        if(res)
        {
            geoEdit.Empiler(*this);
        }
    }
    else if(commande == "L")
    {
        res = AjouterLigne();
        if(res)
        {
            geoEdit.Empiler(*this);
        }
    }
    else if(commande =="LIST")
    {
        geoEdit.Afficher();
    }
    else if(commande =="CLEAR")
    {

    }
    else if(commande == "SAVE")
    {
        Sauvegarder();
    }
    else if(commande == "LOAD")
    {

    }
    else if(commande == "UNDO")
    {

    }
    else if(commande == "REDO")
    {

    }
    else if(commande == "MOVE")
    {

    }
    else if(commande =="DELETE")
    {

    }

    return res;

}

void AfficherErreurCommande() {

    cout<<ERREUR<<"\r\n";
    cout<<COMMENTAIRES<<CMD_PARAM_ERR<<"\r\n";
}
