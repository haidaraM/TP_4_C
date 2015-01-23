/*************************************************************************
                          Selection  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Selection> (fichier Selection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Selection::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Selection::Afficher(ostream & flux)const
{
	//on n'affiche pas les selections
}

void Selection::Supprimer()
{	
	for(vector<Forme*>::const_iterator i = contenues.begin(); i != contenues.end();++i)
	{
			(*i)->Supprimer();
	}
}

void Selection::Deplacer(long abs, long ord)
{
	for(vector<Forme*>::const_iterator i = contenues.begin(); i != contenues.end();++i)
	{
			(*i)->Deplacer(abs, ord);
	}
}

bool Selection::InclusDans(Point p1, Point p2)const
{
	return false;
}


//-------------------------------------------- Constructeurs - destructeur
/*Selection::Selection (const Selection & unSelection) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Selection>" << endl;
#endif

} //----- Fin de Selection (constructeur de copie)*/


Selection::Selection (string name, vector <Forme*> f): Forme(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
	contenues = f;
} //----- Fin de Selection


Selection::~Selection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

