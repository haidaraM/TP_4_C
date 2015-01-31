/*************************************************************************
                           CmdClear  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par ${user}
*************************************************************************/

//---------- Interface de la classe <CmdClear> (fichier CmdClear.h) ------
#if ! defined ( CMD_CLEAR_H )
#define CMD_CLEAR_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>

#include "Commande.h"
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
    CODERETOUR Execute();
    // Mode d'emploi : Execute toutes les commande du fichier

    CODERETOUR UnExecute();
    // Mode d'emploi : Annule toutes les commandes du fichier

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
   

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdClear>

#endif // CMD_CLEAR_H
