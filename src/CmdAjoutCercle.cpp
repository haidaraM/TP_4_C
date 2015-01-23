/*************************************************************************
                           CmdAjoutCercle  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <CmdAjoutCercle> (fichier CmdAjoutCercle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>
#include <vector>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "CmdAjoutCercle.h"
#include "Cercle.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques



bool CmdAjoutCercle::Execute()
{
    char delim =' '; //délimiteur
    vector<string> resultat; // vecteur des elements de la ligne
    stringstream stream(commande); // conversion du string en string stream
    string courant; // element courant

    while(getline(stream, courant, delim))
    {
        //Ajout de l'element courant
        resultat.push_back(courant);
    }
    // Penser à ajouter le test si c'est les arguments sont bien des nombres
    if(resultat.size() != 5)
    {
        cerr <<"ERR"<<"\r\n";
        cerr <<"#Paramètres invalides"<<"\r\n";
        return false;
    }
    else
    {
        // Organisation des elements
        string name = resultat[1];
        long abscisse = strtol(resultat[2].c_str(), NULL, 10);
        long ordonnee = strtol(resultat[3].c_str(), NULL, 10);
        long rayon = strtol(resultat[3].c_str(), NULL, 10);

        Cercle *c = new Cercle(name,rayon, abscisse, ordonnee);

        // mettre la methode qui va mettre à jour la map et empiler la commande
        geoEdit.Ajouter(name, c);
        return true;
    }

}

CmdAjoutCercle::CmdAjoutCercle (string nom ) : Commande(nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdAjoutCercle>" << endl;
#endif
} //----- Fin de CmdAjoutCercle


CmdAjoutCercle::~CmdAjoutCercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdAjoutCercle>" << endl;
#endif
} //----- Fin de ~CmdAjoutCercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
