/*************************************************************************
                           CmdAjoutPoyligne  -  description
                             -------------------
    début                : 16/05/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdAjoutPoyligne> (fichier CmdAjoutPoyligne.h) ------
#if ! defined ( CmdAjoutPoyligne_H )
#define CmdAjoutPoyligne_H

//--------------------------------------------------- Interfaces utilisées
#include "CmdSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Réle de la classe <CmdAjoutPoyligne>
//
//
//------------------------------------------------------------------------ 

class CmdAjoutPoyligne : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Ajoute un polyligne à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif
    // Retour : 
    //          
    //          


    CmdAjoutPoyligne (string cmd );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CmdAjoutPoyligne ( );
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

//----------------------------------------- Types dépendants de <CmdAjoutPoyligne>

#endif // CmdAjoutPoyligne_H
