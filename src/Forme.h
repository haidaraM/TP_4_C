/*************************************************************************
                           Forme  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Forme> (fichier Forme.h) ------
#if ! defined ( FORME_H )
#define FORME_H

//--------------------------------------------------- Interfaces utilisées
#include <string.h>
#include <vector>
using namespace std;

#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Forme>
//
//
//------------------------------------------------------------------------ 

class Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher()const = 0;
    // Mode d'emploi : Affiche les descripteurs de la forme c'est à la dire
    // commande utilisée lors de la création de l'objet.
    //
    // Contrat : Devra être reimplementé par les descendants
    //

//------------------------------------------------- Surcharge d'opérateurs
    Forme & operator = ( const Forme & unForme );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Forme ( const Forme & unForme );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Forme ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Forme ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    // L'etat de la Forme
    bool supprimer;

    // Le nom de la Forme
    string nom;

    // Les points constituant la forme
    vector<Point> points;

private:
//------------------------------------------------------- Attributs privés
    
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Forme>

#endif // FORME_H
