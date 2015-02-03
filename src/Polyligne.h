/*************************************************************************
                         Polyligne  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) 
#if ! defined ( POLYLIGNE_H )
#define POLYLIGNE_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Forme.h"
#include "Point.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Polyligne>
// Classe permettant de gérer un Polyligne
//
//------------------------------------------------------------------------ 

class Polyligne : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher(ostream & flux)const;
    // Mode d'emploi : Affiche les descripteurs du Polyligne
    // Exemple: PL Name X1 Y1 X2 Y2 ... Xn Yn avec n >=1
    //
    // Contrat : Aucun
    //
    
    virtual bool InclusDans(Point p1, Point p2) const;
    // Mode d'emploi : renvoie true si tous les points sont compris dans 
    // le rectangle formé par p1, p2
    //
    // Contrat : Aucun
    //

    virtual void Deplacer (long dx, long dy);
    // Mode d'emploi : Deplace tous les points du polyligne de dx vers l'abscisse
    // et dy vers les ordonnées.
    //
    // COntrat :


//-------------------------------------------- Constructeurs - destructeur
    Polyligne ( const Polyligne & unPolyligne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polyligne (string name, vector <Point> p);
    // Mode d'emploi : constructeur par defaut
    //
    // Contrat :
    //

    virtual ~Polyligne ( );
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
    vector<Point> points;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés
};

#endif // POLYLIGNE_H
