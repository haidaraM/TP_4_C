/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Modele> (fichier Modele.h) ------
#if ! defined ( MODELE_H )
#define MODELE_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <stack> //Pile
#include <string>

#include "Point.h"
#include "Forme.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Modele>
// Classe principale de l'application permettant de gerer touts les objets.
// Il n'y aura qu'une seule instance de cette classe partagée par les
// Commande. Ceci sera possible grâce au pattern Singleton.
//
//------------------------------------------------------------------------

class Modele
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    static Modele & Instance();
    // Mode d'emploi : Renvoie une reference sur la seule instance de cette classe
    //
    // Contrat :

    void Ajouter(string name,  Forme *uneForme);
    // Mode d'emploi : Ajoute une Forme à la Map
    //
    // Contrat :

    void Afficher()const;
    // Mode d'emploi : Afficher toutes les formes
    //
    // Contrat :


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    Modele ( );
    // Mode d'emploi : Constructeur par défaut
    //
    // Contrat :
    //

    virtual ~Modele ( );
    // Mode d'emploi :
    //
    // Contrat :
    //



protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    static Modele m_modele;
    // Attribut de Classe


    typedef map<const string, Forme *> Formes;
    Formes formes;
    // La map contenant toutes les formes (Cercle, Rectangle...)

    typedef stack<Commande*> CommandesUndo;
    CommandesUndo cmdToUndo;
    // Pile des commandes exécutées et qui sont "UNDOABLE"


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Modele>

#endif // MODELE_H
