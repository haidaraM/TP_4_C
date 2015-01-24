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
#include <vector>

#include <string>

using namespace std;

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
class Modele; // Déclaration anticipée

//------------------------------------------------------------------------
// Rôle de la classe <Commande>
// Cette classe permettra de gerer les commandes grâce à une utilisation partielle
// du design pattern command.
// Elle se chargera d'appeler les méthodes de la classe Modele en fonction de la
// commande
//------------------------------------------------------------------------

class Commande
{
//----------------------------------------------------------------- PUBLIC
public:

    bool Execute();
    // Mode d'emploi : Execute la commande courante et l'empile si c'est une
    // commande UNDOABLE
    // Appelera les méthodes qu'il faut

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
    bool AjouterCercle();
    // Mode d'emploi : Ajoute un cercle à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterRectangle();
    // Mode d'emploi : Ajoute un rectangle à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterPolyligne();
    // Mode d'emploi : Ajoute un Polyligne à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterSelection();
    // Mode d'emploi : Ajoute  une selection
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool AjouterLigne();
    // Mode d'emploi : Ajoute une ligne à la Map
    // Si le nom de la forme existe déja, l'ajout ne sera pas effectif

    bool Deplacer();
    // Mode d'emploi : Déplace une Forme ou une selection
    //
    // Contrat :

    bool Sauvegarder()const;
    // Mode d'emploi

    bool Supprimer();
    // Mode d'emploi : Supprimer une Forme ou une selection
    //
    // Contrat :
    bool allDigit(std::vector<string> vect, unsigned int pos=2)const;
    // Mode d'emploi : Test si c'est un vecteur de string n'est composé que de
    // chiffre.
    // Contrat : vect non vide

    bool isDigit(string chaine)const;
    // Mode d'emploi : Test si une chaine représente un nombre
    //
    // Contrat : fournir une chaine non vide

    vector<string> decoupe(char delim =' ')const;
    // Mode d'emploi : Découpe la commande en tableau de string
    //
    // Contrat :

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

    string commande;
    // Chaine de caractères representant la commande

    static Modele & geoEdit;
    // Reference vers la classe principale.
    // Chaque commande pourra ainsi metre à jour la map

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés
};

#endif // COMMANDE_H
