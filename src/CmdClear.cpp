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
    Formes::iterator it;
    for(it=formes.begin(); it != formes.end(); it++)
    {
        delete it->second;
    }
   
} //----- Fin de ~CmdClear


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdClear::UnExecute(bool afficheMsg)
{
    geoEdit.SetMAP(formes);
    formes.clear();
    return GOOD;
}

CODERETOUR CmdClear::Execute(bool afficheMsg)
// Algorithme : On fait une copie de la MAP actuelle et on la vide
{
    formes = geoEdit.GetMAPFormes();
    geoEdit.Clear();
#ifdef VERBOSE
           cout<<OK<<endl;
           cout<<COMMENTAIRES<<"Modèle vidé"<<endl;
#endif
    return GOOD;
}
