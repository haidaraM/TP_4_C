/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Cercle> (fichier Cercle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cercle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Cercle::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Cercle::Afficher()const
{
	
}

//------------------------------------------------- Surcharge d'opérateurs
Cercle & Cercle::operator = ( const Cercle & unCercle )
// Algorithme :
//
{
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Cercle::Cercle ( const Cercle & unCercle )
        : centre(unCercle.centre), rayon(unCercle.rayon)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cercle>" << endl;
#endif

} //----- Fin de Cercle (constructeur de copie)


Cercle::Cercle ( unsigned int ray, long x, long y ):centre(x,y), rayon(ray)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cercle>" << endl;
#endif
} //----- Fin de Cercle (constructeur par défaut)


Cercle::~Cercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cercle>" << endl;
#endif
} //----- Fin de ~Cercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
