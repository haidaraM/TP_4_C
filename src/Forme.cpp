/*************************************************************************
                           Forme  -  Classe répresentant les formes
                             -------------------
    début                : 2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Forme> (fichier Forme.cpp) --
// Cette classe abstraite regroupe les points communs entre les differentes
// formes. Les autres formes hériteront de cette classe.

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Forme.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Forme::Supprimer()
{
    /* La supppression d'une forme, entraine sa suppression dans toutes les
    les selections dans lesquelles elle se trouve.
     */
    selections.clear();
}

void Forme::AjouteSelection(string nomSelection) {
    selections.push_back(nomSelection);
}

vector<string> Forme::GetSelections() const {
    return selections;
}

string Forme::GetNom() const {
    return nom;
}

void Forme::EnleveForme(string nomForme) {
    // Ne fais rien si c'est pas une selection
    // Pourra etre reutilisée pour des amériolations futures
}

vector<Forme *> Forme::GetFormesSelectionnees() const {
    // Par défaut on envoie un vecteur vide
    vector<Forme*> vf;
    return vf;
}


//-------------------------------------------- Constructeurs - destructeur

Forme::Forme (string name):nom(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Forme>" << endl;
#endif

} //----- Fin de Forme


Forme::~Forme ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Forme>" << endl;
#endif
} //----- Fin de ~Forme


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
