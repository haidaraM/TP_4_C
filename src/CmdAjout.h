/*************************************************************************
                           CmdAjout  -  description
                             -------------------
    début                : 16/05/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdAjout> (fichier CmdAjout.h) ------
#if ! defined ( CMD_AJOUT_H )
#define CMD_AJOUT_H

//--------------------------------------------------- Interfaces utilisées
#include "CmdSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdAjout>
// Cette classe gère l'ajout d'une forme dans le Modele : Cercle, Ligne
// Polyligne, Ligne et Selection
//------------------------------------------------------------------------ 

class CmdAjout : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    CODERETOUR AjouterCercle(bool afficheMsg = true);
    // Mode d'emploi : Ajout d'un cercle
    //
    // Retour : ERR_SYNTAXE en cas d'erreur de syntaxe
    //          ERR_NAME_EXISTS si une forme de meme nom existait déjà
    //          GOOD si tout s'est bien déroulé

    CODERETOUR AjouterPolyligne(bool afficheMsg = true);
    // Mode d'emploi : AJout d'un polyligne
    //
    // Retour : ERR_SYNTAXE en cas d'erreur de syntaxe
    //          ERR_NAME_EXISTS si une forme de meme nom existait déjà
    //          GOOD si tout s'est bien déroulé

    CODERETOUR AjouterRectangle(bool afficheMsg = true);
    // Mode d'emploi : Ajoute un rectangle à la Map
    //
    // Retour : ERR_SYNTAXE en cas d'erreur de syntaxe
    //          ERR_NAME_EXISTS si une forme de meme nom existait déjà
    //          GOOD si tout s'est bien déroulé

    CODERETOUR AjouterLigne(bool afficheMsg = true);
    // Mode d'emploi : Ajoute une ligne à la Map
    //
    // Retour : ERR_SYNTAXE en cas d'erreur de syntaxe
    //          ERR_NAME_EXISTS si une forme de meme nom existait déjà
    //          GOOD si tout s'est bien déroulé

    CODERETOUR AjouterSelection(bool afficheMsg = true);
    // Mode d'emploi : Ajoute  une selection
    //
    // Retour : ERR_SYNTAXE en cas d'erreur de syntaxe
    //          ERR_NAME_EXISTS si une forme de meme nom existait déjà
    //          GOOD si tout s'est bien déroulé

//-------------------------------------------- Constructeurs - destructeur
    CmdAjout (string cmd );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjout ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

private:
//------------------------------------------------------- Attributs privés
    void afficheConfirmation(string type, string nom)const;
    // Mode d'emploi : Affiche un message de confirmation d'Ajout

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdAjout>

#endif // CMD_AJOUT_H
