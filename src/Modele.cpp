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
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
Modele Modele::m_modele=Modele();

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


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
    // Libération des formes
    for(Formes::iterator it = formes.begin(); it != formes.end(); it++)
    {
        delete it->second;
    }

    // liberation des commandes restantes
    while(!cmdToUndo.empty())
    {
        delete cmdToUndo.top();
        cmdToUndo.pop();
    }

    while(!cmdToRedo.empty())
    {
        delete cmdToRedo.top();
        cmdToRedo.pop();
    }


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

void Modele::Afficher(ostream & flux) const
{
    for(Formes::const_iterator it = formes.begin(); it != formes.end(); it++)
    {
        it->second->Afficher(flux);
    }
}

void Modele::Sauvegarder(string filename)const
{
    ofstream file(filename.c_str());

    if(file.good())
    {
        Formes::const_iterator it;
        for(it = formes.begin(); it != formes.end(); it++)
        {
            it->second->Afficher(file);
        }
    }

}

void Modele::Empiler(Commande *uneCommande)
{
    cmdToUndo.push(uneCommande);
}

bool Modele::NomExiste(string nom) const {
    return formes.find(nom) != formes.end();
}

Forme *Modele::getForme(string name)const  {
    if(NomExiste(name))
        return formes.find(name)->second;
    else
        return nullptr;
}

void Modele::UNDO() {
    cmdToRedo.push(cmdToUndo.top());// empile sur REDO
    cmdToUndo.top()->UnExecute(); // Annulation de la commande
    cmdToUndo.pop(); //
}

void Modele::EraseForme(string name) {
    formes.erase(name);

}
