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

#include <sstream>


#include "Commande.h"
#include "Modele.h"
#include "Cercle.h"
#include <cctype>
//------------------------------------------------------------- Constantes

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
bool Commande::AjouterCercle()
{
    char delim =' '; //délimiteur
    vector<string> resultat; // vecteur des elements de la ligne
    stringstream stream(commande); // conversion du string en string stream
    string courant; // element courant

    while(getline(stream, courant, delim))
    {
        //Ajout de l'element courant
        resultat.push_back(courant);
    }

    if(resultat.size() != 5 || !allDigit(resultat, 2))
    {
        cerr <<"ERR"<<"\r\n";
        cerr <<"#Paramètres invalides"<<"\r\n";
        return false;
    }
    else
    {
        // Organisation des elements
        string name = resultat[1];
        long abscisse = strtol(resultat[2].c_str(), NULL, 10);
        long ordonnee = strtol(resultat[3].c_str(), NULL, 10);
        long rayon = strtol(resultat[4].c_str(), NULL, 10);

        Cercle *c = new Cercle(name,rayon, abscisse, ordonnee);

        // mettre la methode qui va mettre à jour la map et empiler la commande
        geoEdit.Ajouter(name, c);
        return true;
    }
}

bool Commande::AjouterRectangle() {
    return false;
}

bool Commande::AjouterPolyligne() {
    return false;
}

bool Commande::AjouterSelection() {
    return false;
}

bool Commande::allDigit(vector<string> vect, int pos) {
    bool estNombre = true;
    int i = pos;
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
