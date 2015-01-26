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

    void Ajouter(string name,  Forme *uneForme);
    // Mode d'emploi : Ajoute une Forme à la Map
    // Si un nom de forme est déja présent, la forme sera ignorée
    // Contrat :

    void UNDO();
    // Annule la derniere commande
    //

    void REDO();
    // Execute la derniere commande annuler s'il y'en a
    //

    void Afficher(ostream & flux=cout)const;
    // Mode d'emploi : Affiche toutes les formes soit sur la sortie standard ou dans
    // un fichier
    // Contrat :

    void Sauvegarder(string filename)const;
    //Mode d'emploi : Sauvegarde les formes dans un fichier
    //
    // Contrat : fournir non vide

    void Empiler(Commande *uneCommande);
    //Mode d'emploi : Empile la Commande sur la Pile des commandes
    //
    // Contrat : Commande valide

    static Modele & Instance();
    // Mode d'emploi : Renvoie une reference sur la seule instance de cette classe
    //
    // Contrat :

    bool NomExiste(string nom)const;
    // Mode d'emploi : Verifie si le nom passé par en paramètre existe dans la map
    // Renvoie vrai si le nom existe, faux sinon
    // Contrat :

    Forme * getForme(string name )const;
    // Mode d'emploi : renvoie un pointeur sur la Forme si elle existe,
    // Null sinon

    void EraseForme(string name);
    // Mode d'emploi supprime la forme de la map
    //


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
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

    void liberePileUndo();
    // Mode d'emploi : libere la pile de UNDO

    void liberePileRedo();
    // Mode d'emploi : libere la pile de REDO



protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    static Modele m_modele;
    // Attribut de Classe


    typedef map<const string, Forme *> Formes;
    Formes formes;
    // La map contenant toutes les formes (Cercle, Rectangle...)

    typedef stack<Commande*> Commandes;
    Commandes cmdToUndo;
    // Pile de Pointeur vers les commandes exécutées et qui sont "UNDOABLE"
    //

    Commandes cmdToRedo;
    // Pile de Pointeur vers les commandes exécutées a REDO"
    //



//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Modele>

#endif // MODELE_H
