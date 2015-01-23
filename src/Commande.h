/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) 
#if ! defined ( COMMANDE_H )
#define COMMANDE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class Modele; // Déclaration anticipée

//------------------------------------------------------------------------
// Rôle de la classe <Commande>
// Cette classe abstraite permettra de gerer les commandes grâce au design pattern
// command. Il y'aura une classe par commande.
// Design Pattern Command : Un objet Commande (ou ses descendants) sert à
// communiquer une action à effectuer, ainsi que les arguments requis.
// L'objet est envoyé à une seule méthode dans une classe, qui traite les 
// Commandes du type requis.
//
// Tous les objets Commande doivent avoir accès au Model pour mettre à jour
// directement les formes
//------------------------------------------------------------------------ 

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:

    bool AjouterCercle();
    // Mode d'emploi : Ajout du cercle à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterRectangle();
    // Mode d'emploi : Ajout un rectangle à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterPolyligne();
    // Mode d'emploi : Ajout un Polyligne à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterSelection();
    // Mode d'emploi : Ajout selection
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif


    Commande (string cmd );
    // Mode d'emploi : constructeur par defaut
    //
    // Contrat :
    //

    virtual ~Commande ( );
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

    string commande;
    // Chaine de caractères representant la commande

    static Modele & geoEdit;
    // Reference vers la classe principale.
    // Chaque commande pourra ainsi metre à jour la map et la pile des commandes

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés
};

#endif // COMMANDE_H
