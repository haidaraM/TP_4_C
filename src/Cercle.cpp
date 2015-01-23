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
