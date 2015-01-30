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

void AfficherErreurCommande() {

    cout<<ERREUR<<"\r\n";
    cout<<COMMENTAIRES<<CMD_PARAM_ERR<<"\r\n";
}
