/*************************************************************************
                           CmdClear  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CmdClear> (fichier CmdClear.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "CmdClear.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CmdClear::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


CmdClear::CmdClear (string name ):Commande(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdClear>" << endl;
#endif
} //----- Fin de CmdClear


CmdClear::~CmdClear ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdClear>" << endl;
#endif

   
} //----- Fin de ~CmdClear


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdClear::UnExecute() {
 
    return GOOD;
}

CODERETOUR CmdClear::Execute()
{


    return GOOD;
}
