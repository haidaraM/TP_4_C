/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H )
#define CERCLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Forme.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Cercle>
// Classe permettant de gérer un cercle définit par un centre et un rayon
//
//------------------------------------------------------------------------ 

class Cercle : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher(ostream & flux)const;
    // Mode d'emploi : Affiche les descripteurs du cercle
    // Exemple: C Name X1 Y1 R
    //
    // Contrat : Aucun
    //

    void Deplacer (long dx, long dy);
    // Mode d'emploi : Deplace le centre du cercle
    //

    bool InclusDans(const Point & p1, const Point & p2) const;
    // Mode d'emploi : Renvoie vrai le cercle est inclus dans le rectangle definis
    // par p1 et p2.
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    Cercle ( const Cercle & unCercle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cercle (string name, unsigned int ray, long x, long y );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cercle ( );
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
    Point centre;
    // centre du cercle

    unsigned int rayon;
    // Rayon du cercle

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Cercle>

#endif // CERCLE_H
