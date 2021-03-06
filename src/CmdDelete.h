/*************************************************************************
                           CmdDelete  -  description
                             -------------------
    début                : 30/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdDelete> (fichier CmdDelete.h) ------
#if ! defined ( CMD_DELETE_H )
#define CMD_DELETE_H

//--------------------------------------------------- Interfaces utilisées
#include "Forme.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdDelete>
// Gestion de la Commande LOAD qui prend en paramètre un fichier et va ajouter
// la description des Forme se trouvant dans le fichier
//------------------------------------------------------------------------ 

class CmdDelete : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute(bool afficheMsg = true);
    // Mode d'emploi : Execute la commande
    //
    // COntrat :
    // Retour : ERR_SYNTAXE
    //          ERR_UNKNOWN_NAME
    //          GOOD

    CODERETOUR UnExecute(bool afficheMsg = false);
    // Mode d'emploi : Annule la commande
    // Remarque :le UNDO de la suppression d'une forme n'entraine pas sa remise dans les
    // selections dans lesquelles elles étaient
    //
    // Contrat : commande exécutée une fois

//-------------------------------------------- Constructeurs - destructeur
    CmdDelete(string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdDelete( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    void deplacerFormes(vector<Forme *>&);
    // Mode d'emploi : Deplace un ensemble dans les Formes supprimées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    vector<Forme*> formesSupprimees;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdDelete>

#endif // CMD_DELETE_H
