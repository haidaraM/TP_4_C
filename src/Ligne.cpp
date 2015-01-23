/*************************************************************************
                          Ligne  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Ligne> (fichier Ligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Ligne::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Ligne::Afficher(ostream & flux)const
{	
	long a1 = points.at(0).GetAbscisse();
	long o1 = points.at(0).GetOrdonnee();
	long a2 = points.at(1).GetAbscisse();
	long o2 = points.at(1).GetOrdonnee();
	flux<<"L "<<nom<<" "<<a1<<" "<<o1<<" "<<a2<<" "<<o2<<"\r\n";
}


//-------------------------------------------- Constructeurs - destructeur
Ligne::Ligne ( const Ligne & unLigne ) : Polyligne(unLigne.nom, unLigne.points)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ligne>" << endl;
#endif
} //----- Fin de Ligne (constructeur de copie)


Ligne::Ligne (string name, vector <Point> p): Polyligne(name, p)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
} //----- Fin de Ligne


Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

