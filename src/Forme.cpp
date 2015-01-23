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
// type Forme::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Forme::Forme ( const Forme & unForme )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Forme>" << endl;
#endif
} //----- Fin de Forme (constructeur de copie)


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
