/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
Modele Modele::m_modele=Modele();

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Modele::Méthode ( liste de paramétres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



Modele::Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
Modele &Modele::Instance() {
    return m_modele;
}

void Modele::Ajouter(string name, Forme *uneForme)
{
    formes.insert(make_pair(name, uneForme));
}

void Modele::Afficher() const
{
    for(Formes::const_iterator it = formes.begin(); it != formes.end(); it++)
    {
        it->second->Afficher();
    }
}
