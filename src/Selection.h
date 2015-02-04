/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection.h) ------
#include "Polyligne.h"
#include "Point.h"

#if ! defined (SELECTION__H )
#define SELECTION__H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Selection>
// Classe permettant de gérer une Selection qui contient des pointeurs vers
// des Forme
//------------------------------------------------------------------------ 

class Selection : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher(ostream & flux)const;
    // Mode d'emploi : N'affiche rien pour une Selection
    //
    // Contrat : Aucun
    //
    
    void Supprimer();
    // Mode d'emploi : supprime toutes les formes de la selection
    //
    // Contrat : aucun
    //
    
    void Deplacer(long abs, long ord);
    // Mode d'emploi : Déplace toutes les formes de la selection selon le
    // vecteur formé par abs, ord.
    //
    // Contrat : aucun
    //
    
    bool InclusDans(const Point & p1, const Point & p2)const;
    // Mode d'emploi : Une selection ne peut pas être inclue dans une autre
    // selection. Renvoie systématiquement false
    //
    // Contrat : Aucun
    //

    void EnleveForme(string nomForme);
    // Mode d'emploi : Enlève la Forme de la selection
    //

    vector <Forme*> GetFormesSelectionnees()const;
    // Mode d'emploi : Renvoie un vecteur de Forme composant la selection

    Selection (string name, vector<Forme*>& f);
    // Mode d'emploi : le nom de la selection et les formes qu'elle contiendra
    //
    // Contrat : Aucun
    //

    virtual ~Selection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

    void majFormeSelectionnees();
    // Mode d'emploi : signale aux Forme qu'il font partis de la selection

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    vector <Forme*> contenues;
    // Pointeur vers les formes se trouvant dans la selection

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Selection>

#endif // Ligne__H


