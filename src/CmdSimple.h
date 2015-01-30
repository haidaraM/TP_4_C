/*************************************************************************
                           CmdSimple  -  description
                             -------------------
    début                : 16/05/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdSimple> (fichier CmdSimple.h) ------
#if ! defined ( CMDSIMPLE_H )
#define CMDSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdSimple>
//
//
//------------------------------------------------------------------------

class CmdSimple : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    virtual CODERETOUR Execute();
    // Mode d'emploi :

    virtual CODERETOUR UnExecute();
    // Mode d'emploi : Annule la commande simple

    CmdSimple (string name );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetNom()const;
    // Mode d'emploi : renvoie le nom de la Forme correspondant à la commande
    // ou le second Argument de la commande

    virtual ~CmdSimple ( );
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

//----------------------------------------- Types dépendants de <CmdSimple>

#endif // CMDSIMPLE_H
