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
const string COMMENTAIRES("#");
const string ERREUR("ERR");
const string OK("OK");

// Code de retour des Commandes
enum CODERETOUR {
    ERR_NAME_EXISTS=-1,ERR_SYNTAXE=0, GOOD=1,  ERR_UNKNOWN_NAME=2, ERR_FILE=3,
    ERR_READING_FILE=4
};



//------------------------------------------------------------------ Types
class Modele; // Déclaration anticipée


//------------------------------------------------------------------------
// Rôle de la classe <Commande>
// Cette classe permettra de gerer les commandes grâce à une utilisation
// du design pattern Command.
// Elle se chargera d'appeler les méthodes de la classe Modele en fonction de la
// commande. C'est elle qui dirigera l'application.
//------------------------------------------------------------------------

class Commande
{
//----------------------------------------------------------------- PUBLIC
public:

    virtual CODERETOUR Execute(bool afficheMsg = true)=0;
    // Mode d'emploi : Execute la commande


    virtual CODERETOUR UnExecute(bool afficheMsg = true)=0;
    // Mode d'emploi : Annule la commande
    //
    // Contrat : commande excutée une fois

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

    CODERETOUR Supprimer();
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
    // Chaque commande pourra ainsi mettre à jour la map sans en créer une
    // nouvelle instance

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés
};

void AfficherErreurCommande();
// Mode d'emploi : Affiche un message d'erreur sur la sortie d'erreur si la
// syntaxe de la commande est incorrecte

#endif // COMMANDE_H
