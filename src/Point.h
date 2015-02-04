/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
// Classe permettant de gérer un Point définie par une abscisse et une
// ordonnée
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    long GetAbscisse()const;
    // Mode d'emploi : Renvoie l'asbcisse du point
    //
    // Contrat : Aucun
    //

    long GetOrdonnee()const;
    // Mode d'emploi : Renvoie l'ordonnée du point
    //
    // Contrat : Aucun
    //

    void Deplacer(long dx, long dy);
    // Mode d'emploi : Déplace le point de dx en abscisse et dy en ordonnée
    //
    // Contrat : Aucun


//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point ( long absc, long ordo );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
    // Mode d'emploi : Desctructeur
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
    long abscisse;
    long ordonnee;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés
};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
