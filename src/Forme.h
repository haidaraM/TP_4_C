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
    // Contrat : fournir un flux valide
    //

    virtual bool InclusDans(Point p1, Point p2)const =0;
    // Mode d'emploi : Verifie si la forme se trouve entre p1 et p2
    // Renvoie vrai si c'est le cas, 0 sinon

    virtual void Deplacer (long x, long y) =0;
    // Mode d'emploi : Deplace tous les points de la forme

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


    virtual void Supprimer ();



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

    // Ensemble des Selection dans lequel la Forme se trouve


private:
//------------------------------------------------------- Attributs privés
    
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Forme>

#endif // FORME_H
