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
#include <stack>
#include <string>

#include "Point.h"
#include "Forme.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types 
typedef map<const string, Forme *> Formes;
typedef stack<Commande*> Commandes;
//------------------------------------------------------------------------ 
// Rôle de la classe <Modele>
// Classe principale de l'application permettant de gerer touts les objets.
// Il n'y aura qu'une seule instance de cette classe partagée par les
// Commande. Ceci sera assuré grâce au pattern Singleton.
//
//------------------------------------------------------------------------

class Modele
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Ajouter(string name,  Forme *uneForme);
    // Mode d'emploi : Ajoute une Forme à la Map.
    // Si une forme du même nom est déja présente, l'ajout ne s'effectuera pas
    //
    // Contrat : Aucun

    void Undo();
    // Mode d'emploi : Annule la derniere commande (s'il y en a) effectuée qui a eu un effet sur
    // le modèle.
    //
    // Contrat : Aucun

    void Redo();
    // Mode d'emploi : Execute la derniere commande annulée  (s'il y'en a)
    //
    // Contrat : Aucun

    void Afficher(ostream & flux=cout)const;
    // Mode d'emploi : Affiche toutes les formes soit sur la sortie standard ou dans
    // un fichier.
    //
    // Contrat :

    void Sauvegarder(ofstream &file)const;
    //Mode d'emploi : Sauvegarde les formes dans un fichier.
    //
    // Contrat : fournir non vide

    void Empiler(Commande *uneCommande);
    //Mode d'emploi : Ajoute la Commande sur la Pile des commandes.
    //
    // Contrat : Commande valide

    void Clear();
    // Mode d'emploi : Vide le modèle actuelle c'est à dire supprime toutes les formes
    // actuellement présente.
    //
    // Contrat :

    bool FormeExiste(string nom)const;
    // Mode d'emploi : Verifie si le nom passé en paramètre existe dans la map
    // Renvoie vrai si le nom existe, faux sinon
    //
    // Contrat : Aucun

    Forme *GetForme(string name)const;
    // Mode d'emploi : Renvoie un pointeur sur la Forme dont le nom est passé en paramètre.
    // Si la forme n'existe pas, on renvoie null.
    //
    // Contrat :

    void EraseForme(string name);
    // Mode d'emploi : Supprime la forme dont le nom est passé en paramètre de la map
    //
    // COntrat :

    Formes GetMAPFormes()const;
    // Mode d'emploi : Renvoie toutes les formes actuellement présente
    //
    // Contrat :

    void SetMAP(const Formes &uneMap);
    // Mode d'emploi : Remplace l'ancienne map par une nouvelle
    //
    // Contrat : ancienne map vide

    vector<Forme *> GetFormeSelection(const Point & p1,const Point& p2) const;
    // Mode d'emploi : Renvoi les Formes qui sont comprises entre
    // p1 et p2

    void CasserLien(const Forme *uneForme);
    // Mode d'emploi : Casse les liens Selection -> Forme de la forme
    // passée en paramètre

    static Modele & Instance();
    // Mode d'emploi : Renvoie une reference sur la seule instance de cette classe
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
    // Mode d'emploi : Destructeur
    //
    // Contrat :
    //

    void liberePileUndo();
    // Mode d'emploi : libere la pile de Undo

    void liberePileRedo();
    // Mode d'emploi : libere la pile de Redo


protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

    static Modele m_modele;
    // Attribut de Classe

    Formes formes;
    // La map contenant toutes les formes (Cercle, Rectangle...)

    Commandes cmdToUndo;
    // Pile de Pointeur vers les commandes exécutées et qui sont "UNDOABLE"

    Commandes cmdToRedo;
    // Pile de Pointeur vers les commandes exécutées a "Redo"




//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Modele>

#endif // MODELE_H
