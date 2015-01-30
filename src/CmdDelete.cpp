/*************************************************************************
                           CmdSuppression  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CmdDelete> (fichier CmdDelete.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdDelete.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CmdDelete::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


CmdDelete::CmdDelete(string name ):Commande(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdDelete>" << endl;
#endif
} //----- Fin de CmdDelete


CmdDelete::~CmdDelete( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdDelete>" << endl;
#endif
    for (unsigned int i = 0; i < formesSupprimees.size(); ++i)
    {
        delete formesSupprimees[i];
    }

} //----- Fin de CmdDelete------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

CODERETOUR CmdDelete::Execute()
{
    vector<string> arguments = decoupe();

    // Si l'utilisateur n'a fourni aucun objet à supprimer
    if(arguments.size() == 1)
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {
        // Vérification de la présence de toutes les Formes
        for(unsigned int i = 1; i < arguments.size(); ++i)
        {
            if(!geoEdit.FormeExiste(arguments[i]))
            {
                cout <<"Forme : "<<arguments[i]<<" inconnue!"<<endl;
                return ERR_UNKNOWN_NAME;
            }
        }

        // Sauvegarde puis suppression des formes
        for(unsigned int i = 1; i<arguments.size(); ++i)
        {
            // ajout dans le vecteur de Formes supprimées
            formesSupprimees.push_back(geoEdit.GetForme(arguments[i]));
            // Suppression de la Map
            geoEdit.EraseForme(arguments[i]);
        }
        return GOOD;

    }
}

//------------------------------------------------------- Méthodes privées
CODERETOUR CmdDelete::UnExecute() {
    return GOOD;
}
