/*************************************************************************
                           Forme  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Forme> (fichier Forme.h) ------
#if ! defined ( FORME_H )
#define FORME_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
using namespace std;
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Forme>
//
//
//------------------------------------------------------------------------ 

class Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher(ostream & flux)const = 0;
    // Mode d'emploi : Affiche les descripteurs de la forme c'est à dire la
    // commande utilisée lors de la création de l'objet.
    //
    // Contrat : fournir un flux valide
    //

    virtual bool InclusDans(Point p1, Point p2)const =0;
    // Mode d'emploi : Verifie si la forme se trouve entre p1 et p2
    // Renvoie vrai si c'est le cas, 0 sinon
    //
    // Contrat :

    virtual void Deplacer (long x, long y) =0;
    // Mode d'emploi : Deplace le Forme
    //
    // Contrat :

    virtual void Supprimer ();
    // Mode d'emploi : Supprime la Forme dans les selections dans lesquelles
    // elle se trouve.
    //
    // Contrat :

    virtual void EnleveForme(string nomForme);
    // Mode d'emploi : Enlève une Forme de la selection
    //
    // Contrat :

    virtual vector <Forme*> GetFormesSelectionnees()const;
    // Mode d'emploi : Renvoie les Formes composant une selection
    //
    // Contrat :

    string GetNom()const;
    // Mode d'emploi : Renvoie le nom de la Forme
    //
    // Contrat : Aucun

    void AjouteSelection(string nomSelection);
    // Mode d'emploi : Signale à la forme qu'elle fait partie de la selection
    // dont le nom est passé en paramètre
    //
    // Contrat : nomSelection non vide

    vector<string> GetSelections()const;
    // Mode d'emploi : Recupère la liste des selections d'une forme
    //
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    Forme (string name);
    // Mode d'emploi : Contructeur par défaut
    //
    // Contrat :
    //

    virtual ~Forme ( );
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

    string nom;
    // Le nom de la Forme

    vector<string> selections;
    // vecteur de nom des selections dans lesquelles la forme se trouve


private:
//------------------------------------------------------- Attributs privés
    
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Forme>

#endif // FORME_H
