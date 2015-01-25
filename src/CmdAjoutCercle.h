/*************************************************************************
                           CmdAjoutCercle  -  description
                             -------------------
    début                : 16/05/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdAjoutCercle> (fichier CmdAjoutCercle.h) ------
#if ! defined ( CMDAJOUTCERCLE_H )
#define CMDAJOUTCERCLE_H

//--------------------------------------------------- Interfaces utilisées
#include "CmdSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Réle de la classe <CmdAjoutCercle>
//
//
//------------------------------------------------------------------------ 

class CmdAjoutCercle : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Ajoute un cercle à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif
    // Retour : 1 si la commande s'est bien exécutée
    //          0 si la syntaxe est incorrecte
    //          -1 si le nom de la forme existe déja

    CODERETOUR UnExecute();
    // Mode d'emploi execute la commande inverse => supprimer


    CmdAjoutCercle (string cmd );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutCercle ( );
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

//----------------------------------------- Types dépendants de <CmdAjoutCercle>

#endif // CMDAJOUTCERCLE_H
