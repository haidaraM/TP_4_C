/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#include "Polyligne.h"
#include "Point.h"

#if ! defined (RECTANGLE__H )
#define RECTANGLE__H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Rectangle>
// Classe permettant de gérer un Rectangle
//
//------------------------------------------------------------------------ 

class Rectangle : public Polyligne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher(ostream & flux)const;
    // Mode d'emploi : Affiche les descripteurs du Rectangle
    // Exemple: R Name X1 Y1 X2 Y2
    //
    // Contrat : Aucun
    //



//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( const Rectangle & unRectangle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Rectangle (string name, vector <Point> p);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Rectangle ( );
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

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Rectangle>

#endif // RECTANGLE__H
