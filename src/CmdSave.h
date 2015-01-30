/*************************************************************************
                           CmdSave  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <CmdSave> (fichier CmdSave.h) ------
#if ! defined ( CmdSave_H )
#define CmdSave_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>

#include "CmdSimple.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdSave>
// Gestion de la Commande Save qui prend en paramètre un fichier et va 
// sauvegarder le Modele courant dans un fichier
//------------------------------------------------------------------------ 

class CmdSave : public CmdSimple
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Execute toutes les commande du fichier


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

#endif // CmdSave_H
