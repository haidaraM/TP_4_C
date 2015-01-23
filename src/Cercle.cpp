/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 16/01/2015
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

void Cercle::Afficher(ostream & flux)const
{
    flux<<"C "<<nom<<" "<<centre.GetAbscisse()<<" "<<centre.GetOrdonnee()<<" "<<rayon<<"\r\n";
}

bool Cercle::InclusDans(Point p1, Point p2)const
{
	int absmin = centre.GetAbscisse() - rayon;
	int absmax = centre.GetAbscisse() + rayon;
	int ordmin = centre.GetOrdonnee() - rayon;
	int ordmax = centre.GetOrdonnee() + rayon;
	
	if((absmin >= p1.GetAbscisse() && absmax <= p2.GetAbscisse()) || 
		(absmin >= p2.GetAbscisse() && absmax <= p1.GetAbscisse()))
	{
		if ((ordmin >= p1.GetOrdonnee() && ordmax <= p2.GetOrdonnee()) ||
			(ordmin >= p2.GetOrdonnee() && ordmax <= p1.GetOrdonnee()))
			{
				return true;
			}
	}
	
	return false;
}


//-------------------------------------------- Constructeurs - destructeur
Cercle::Cercle ( const Cercle & unCercle )
        :Forme(unCercle.nom), centre(unCercle.centre), rayon(unCercle.rayon)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cercle>" << endl;
#endif

} //----- Fin de Cercle (constructeur de copie)


Cercle::Cercle (string name, unsigned int ray, long x, long y ):Forme(name),centre(x,y), rayon(ray)
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
