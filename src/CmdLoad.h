/*************************************************************************
                           CmdLoad  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <CmdLoad> (fichier CmdLoad.h) ------
#if ! defined ( CMDLOAD_H )
#define CMDLOAD_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>

#include "Commande.h"
#include "CmdAjout.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdLoad>
// Gestion de la Commande LOAD qui prend en paramètre un fichier et va ajouter
// la description des Forme se trouvant dans le fichier
//------------------------------------------------------------------------ 

class CmdLoad : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Execute toutes les commande du fichier

    CODERETOUR UnExecute();
    // Mode d'emploi : Annule toutes les commandes du fichier

    CmdLoad (string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdLoad ( );
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
    typedef stack<CmdAjout *> Commandes;
    Commandes cmds;
    // pile de commande lues dans le fichier

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdLoad>

#endif // CMDLOAD_H
