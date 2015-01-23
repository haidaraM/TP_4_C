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
#include <vector>
#include <sstream>


#include "Commande.h"
#include "Modele.h"
#include "Cercle.h"

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
    // Penser à ajouter le test si c'est les arguments sont bien des nombres
    if(resultat.size() != 5)
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
        long rayon = strtol(resultat[3].c_str(), NULL, 10);

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
