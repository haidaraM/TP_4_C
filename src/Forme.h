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
#include <string>
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
    // Si la Forme est une selection, toutes les formes de la selection
    // seront déplacées.

    virtual void Supprimer ();
    // Mode d'emploi : Supprime la Forme dans les selections dans lesquelles
    // elle se trouve
    // Contrat :
    //

    virtual void AjouteSelection(string nomSelection);
    // Mode d'emploi : Ajoute un bom de selection dans le tableau

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

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

    bool supprimer;
    // L'etat de la Forme

    string nom;
    // Le nom de la Forme

    vector<string> selections;
    // vecteur de nom des selections dans lesquelles la forme se trouve


private:
//------------------------------------------------------- Attributs privés
    
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Forme>

#endif // FORME_H
