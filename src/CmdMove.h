/*************************************************************************
                           CmdMove  -  description
                             -------------------
    début                : 26/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdMove> (fichier CmdMove.h) ------
#if ! defined ( CMD_MOVE_H )
#define CMD_MOVE_H

//--------------------------------------------------- Interfaces utilisées
#include "CmdAjout.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdMove>
// Gestion de la commande MOVE qui deplace une Forme
//------------------------------------------------------------------------ 

class CmdMove : public Commande
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute(bool afficheMsg = true);
    // Mode d'emploi : Execute la commande
    //
    // Contrat :
    // Retour : ERR_UNKNOWN_NAME : si la forme à déplacer n'existe pas
    //          ERR_SYNTAXE
    //          GOOD

    CODERETOUR UnExecute(bool afficheMsg = true);
    // Mode d'emploi : Annule la commande c'est à dire le déplacement de la
    // forme
    //
    // Contrat : commande exécutée une fois
    // Retour : GOOD

//-------------------------------------------- Constructeurs - destructeur
    CmdMove (string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdMove ( );
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

//----------------------------------------- Types dépendants de <CmdMove>

#endif // CMD_MOVE_H
