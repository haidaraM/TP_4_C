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
    virtual void Afficher(ostream & flux)const = 0;
    // Mode d'emploi : Affiche les descripteurs de la forme c'est à la dire
    // commande utilisée lors de la création de l'objet.
    //
    // Contrat : Devra être reimplementé par les descendants
    //



//-------------------------------------------- Constructeurs - destructeur
    Forme ( const Forme & unForme );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Forme (string name);
    // Mode d'emploi : Contructeur par défaut
    //
    // Contrat :
    //

    virtual ~Forme ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    /*
    virtual bool InclusDans(Point p1, Point p2);
    virtual void Supprimer ();
    virtual void Deplacer (long x, long y);
    virtual void Afficher (ostream & sortie);*/
    

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

private:
//------------------------------------------------------- Attributs privés
    
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Forme>

#endif // FORME_H
