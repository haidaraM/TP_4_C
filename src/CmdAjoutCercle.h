/*************************************************************************
                           CmdAjoutCercle  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdAjoutCercle> (fichier CmdAjoutCercle.h) ------
#if ! defined ( CMDAJOUTCERCLE_H )
#define CMDAJOUTCERCLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
class Modele; // Déclaration anticipée
//------------------------------------------------------------------------ 
// Réle de la classe <CmdAjoutCercle>
//
//
//------------------------------------------------------------------------ 

class CmdAjoutCercle : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:

    bool Execute();
    // Mode d'emploi : Execute la commande permettant d'ajouter un cercle à la Map
    //
    // Contrat : Aucun
    //

    CmdAjoutCercle (string nom );
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
