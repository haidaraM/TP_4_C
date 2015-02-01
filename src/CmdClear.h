/*************************************************************************
                           CmdClear  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdClear> (fichier CmdClear.h) ------
#if ! defined ( CMD_CLEAR_H )
#define CMD_CLEAR_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include "Forme.h"
#include "Commande.h"
#include "Modele.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdClear>
// Gestion de la Commande CLEAR qui supprime tous les objets présents dans
//
//------------------------------------------------------------------------ 

class CmdClear : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute(bool afficheMsg = true);
    // Mode d'emploi : Execute la commande

    CODERETOUR UnExecute(bool afficheMsg = true);
    // Mode d'emploi : Annule la commande
    //
    // Contrat : commande excutée une fois

    CmdClear (string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdClear ( );
    // Mode d'emploi : Destructeur
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

    Formes formes;
    // La map contenant toutes les formes (Cercle, Rectangle...)

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdClear>

#endif // CMD_CLEAR_H
