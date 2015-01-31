/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <CmdDelete> (fichier CmdDelete.h) ------
#if ! defined ( CMD_SUPPRESSION_H )
#define CMD_SUPPRESSION_H

//--------------------------------------------------- Interfaces utilisées
#include "Forme.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdDelete>
// Gestion de la Commande LOAD qui prend en paramètre un fichier et va ajouter
// la description des Forme se trouvant dans le fichier
//------------------------------------------------------------------------ 

class CmdDelete : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Execute toutes les commande du fichier

    CODERETOUR UnExecute();
    // Mode d'emploi : Annule toutes les commandes du fichier

//-------------------------------------------- Constructeurs - destructeur
    CmdDelete(string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdDelete( );
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
    vector<Forme*> formesSupprimees;


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdDelete>

#endif // CMD_SUPPRESSION_H
