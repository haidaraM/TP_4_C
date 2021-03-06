/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Point::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
long Point::GetAbscisse()const
{
	return abscisse;
}

long Point::GetOrdonnee()const
{
	return ordonnee;
}

void Point::Deplacer(long dx, long dy)
{
	abscisse += dx;
	ordonnee += dy;
}

//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & unPoint )
// Algorithme :
//
{
    abscisse = unPoint.abscisse;
    ordonnee = unPoint.ordonnee;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Point::Point (const Point & unPoint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
    abscisse = unPoint.abscisse;
    ordonnee = unPoint.ordonnee;
} //----- Fin de Point (constructeur de copie)


Point::Point (long absc, long ordo  ):abscisse(absc), ordonnee(ordo)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
