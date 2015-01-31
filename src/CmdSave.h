/*************************************************************************
                           CmdSave  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
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
// sauvegarder le Modele courant dans ce fichier
//------------------------------------------------------------------------ 

class CmdSave : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Sauvegarde le modele courant dans un fichier
    // COntrat :


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
