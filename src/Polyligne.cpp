/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Polyligne> (fichier Polyligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------- Méthodes publiques
// type Polyligne::Méthode ( liste de paramétres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Polyligne::Afficher()const
{

}

//------------------------------------------------- Surcharge d'opérateurs
Polyligne & Polyligne::operator = ( const Polyligne & unPolyligne )
{
    return *this;
}


//-------------------------------------------- Constructeurs - destructeur
Polyligne::Polyligne ( const Polyligne & unPolyligne ) : Forme(unPolyligne.nom)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyligne>" << endl;
#endif
} 


Polyligne::Polyligne (string name ):Forme(name)

{
#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
}


Polyligne::~Polyligne ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
}
