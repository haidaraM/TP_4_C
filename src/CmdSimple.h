/*************************************************************************
                           CmdSimple  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdSimple> (fichier CmdSimple.h) ------
#if ! defined ( CMD_SIMPLE_H )
#define CMD_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CmdSimple>
// Cette classe regroupe les commandes qui ont un comportement similaire
// et qui ne necessite pas un traitement particulier : commandes d'ajout et
// et de sauvegarde
//------------------------------------------------------------------------

class CmdSimple : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual CODERETOUR Execute(bool afficheMsg = true);
    // Mode d'emploi : Execute la commande (SAVE ou ajout d'une nouvelle forme)
    // Par défaut on affiche un message de confirmation
    //
    // Retour : ERR_SYNTAXE : en cas d'erreur de syntaxe
    //          ERR_NAME_EXISTS : si une forme de meme nom existait déjà
    //          GOOD : si tout s'est bien déroulé
    //          ERR_FILE : s'il y'a eu un problème lors de l'ouverture d'un fichier

    virtual CODERETOUR UnExecute(bool afficheMsg = true);
    // Mode d'emploi : Annule la commande
    // Par défaut on affiche un message de confirmation.
    //
    // Contrat : commande executée une fois
    // Retour : GOOD


//-------------------------------------------- Constructeurs - destructeur
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

#endif // CMD_SIMPLE_H
