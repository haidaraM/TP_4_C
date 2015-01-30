/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <CmdSuppression> (fichier CmdSuppression.h) ------
#if ! defined ( CMD_SUPPRESSION_H )
#define CMD_SUPPRESSION_H

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "CmdSuppression.h"
#include "Forme.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <CmdSuppression>
// Gestion de la Commande LOAD qui prend en paramètre un fichier et va ajouter
// la description des Forme se trouvant dans le fichier
//------------------------------------------------------------------------ 

class CmdSuppression : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    CODERETOUR Execute();
    // Mode d'emploi : Execute toutes les commande du fichier

    CODERETOUR UnExecute();
    // Mode d'emploi : Annule toutes les commandes du fichier

    CmdSuppression (string name );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~CmdSuppression ( );
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

//----------------------------------------- Types dépendants de <CmdSuppression>

#endif // CMD_SUPPRESSION_H
