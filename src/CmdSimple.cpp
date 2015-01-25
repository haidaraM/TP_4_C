/*************************************************************************
                           CmdSimple  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CmdSimple> (fichier CmdSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdSimple.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


CmdSimple::CmdSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdSimple>" << endl;
#endif
} //----- Fin de CmdSimple


CmdSimple::~CmdSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdSimple>" << endl;
#endif
} //----- Fin de ~CmdSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
