/*************************************************************************
                           CmdSave  -  description
                             -------------------
    début                : 26/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdSave> (fichier CmdSave.h) ------
#if ! defined ( CMD_SAVE_H )
#define CMD_SAVE_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>

#include "CmdSimple.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdSave>
// Gestion de la Commande Save qui prend en paramètre un fichier et va 
// sauvegarder le Modele courant dans ce fichier.
//------------------------------------------------------------------------ 

class CmdSave : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute(bool afficheMsg = true);
    // Mode d'emploi : Sauvegarde le modele courant dans un fichier
    //
    // COntrat :
    // Retour : ERR_SYNTAXE : si la syntaxe n'est pas correcte
    //          ERR_FILE : problème de fichier
    //          GOOD tout s'est bien passé comme prévu

    CODERETOUR UnExecute(bool afficheMsg = true);
    // Mode d'emploi : Ne fais rien car une sauvegarde n'est pas annulable
    //
    // Contrat : Aucun
    // Retour : GOOD

//-------------------------------------------- Constructeurs - destructeur
    CmdSave (string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdSave ( );
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

private:
//------------------------------------------------------- Attributs privés

};

//----------------------------------------- Types dépendants de <CmdSave>

#endif // CMD_SAVE_H
