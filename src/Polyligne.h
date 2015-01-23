/*************************************************************************
                         Polyligne  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) 
#if ! defined ( POLYLIGNE_H )
#define POLYLIGNE_H

//--------------------------------------------------- Interfaces utilisées
#include "Forme.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polyligne>
// Classe permettant de gérer un Polyligne
//
//------------------------------------------------------------------------ 

class Polyligne : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher()const;
    // Mode d'emploi : Affiche les descripteurs du Polyligne
    // Exemple: PL Name X1 Y1 X2 Y2 ... Xn Yn
    //
    // Contrat : Aucun
    //


    //------------------------------------------------- Surcharge d'opérateurs
    Polyligne & operator = ( const Polyligne & unPolyligne );
    // Mode d'emploi : Operateur d'affectation
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polyligne ( const Polyligne & unPolyligne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polyligne ( );
    // Mode d'emploi : constructeur par defaut
    //
    // Contrat :
    //

    virtual ~Polyligne ( );
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

#endif // POLYLIGNE_H
