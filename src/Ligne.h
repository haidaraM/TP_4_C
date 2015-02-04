/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#include "Polyligne.h"
#include "Point.h"

#if ! defined (LIGNE__H )
#define LIGNE__H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Ligne>
// Classe permettant de gérer une Ligne définit par deux points
//
//------------------------------------------------------------------------ 

class Ligne : public Polyligne
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher(ostream & flux)const;
    // Mode d'emploi : Affiche les descripteurs du Ligne
    // Exemple: L Name X1 Y1 X2 Y2
    //
    // Contrat : Aucun
    //

//-------------------------------------------- Constructeurs - destructeur
    Ligne ( const Ligne & unLigne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ligne (string name, vector <Point> p);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ligne ( );
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

//----------------------------------------- Types dépendants de <Ligne>

#endif // Ligne__H

