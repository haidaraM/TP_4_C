/*************************************************************************
                           CmdLoad  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <CmdLoad> (fichier CmdLoad.h) ------
#if ! defined ( CMDLOAD_H )
#define CMDLOAD_H

//--------------------------------------------------- Interfaces utilisées
#include <stack>

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
    CODERETOUR Execute(bool afficheMsg = false);
    // Mode d'emploi : Execute toutes les commande du fichier

    CODERETOUR UnExecute(bool afficheMsg = false);
    // Mode d'emploi : Annule toutes les commandes du fichier
    //
    // Contrat : commande excutée une fois

//-------------------------------------------- Constructeurs - destructeur
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

    void afficherConfirmation(string file,int nbFormes)const;
    // Mode d'emploi : Affiche une confirmation de la lecture du fichier

    void reExecute();
    // Mode d'emploi : Execute les commandes déjà enregistrées lorsqu'on fait
    // un REDO

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    vector<CmdAjout*>cmds;
    // Vecteur de commandes qui ont été lues dans le fichier

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <CmdLoad>

#endif // CMDLOAD_H
