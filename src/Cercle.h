/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : ${date}
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
//
//
//------------------------------------------------------------------------ 

class Cercle : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher()const;
    // Mode d'emploi : Affiche les descripteurs du cercle
    // Exemple : C: C c11 12 15 45 pour un cercle de c11 de centre (12,12)
    // et de rayon 45
    //
    // Contrat : Aucun
    //


//------------------------------------------------- Surcharge d'opérateurs
    Cercle & operator = ( const Cercle & unCercle );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cercle ( const Cercle & unCercle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cercle (unsigned int ray );
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
    unsigned int rayon;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Cercle>

#endif // CERCLE_H
