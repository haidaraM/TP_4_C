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
// Réle de la classe <CmdAjout>
//
//
//------------------------------------------------------------------------ 

class CmdAjout : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    CODERETOUR AjouterCercle();
    // Mode d'emploi : Ajout d'un cercle
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    CODERETOUR AjouterPolyligne();
    // Mode d'emploi : AJout d'un polyligne
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    CODERETOUR AjouterRectangle();
    // Mode d'emploi : Ajoute un rectangle à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    CODERETOUR AjouterLigne();
    // Mode d'emploi : Ajoute une ligne à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    CODERETOUR AjouterSelection();
    // Mode d'emploi : Ajoute  une selection
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif
    // Retour : 1 si la commande s'est bien exécutée
    //          0 si la syntaxe est incorrecte
    //          -1 si le nom de la selection existe déja


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

//----------------------------------------- Types dépendants de <CmdAjout>

#endif // CMD_AJOUT_H