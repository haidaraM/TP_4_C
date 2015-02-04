/*************************************************************************
                        CmdDelete  -  description
                            -------------------
début                : 30/01/2015
copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
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


CODERETOUR CmdDelete::Execute(bool afficheMsg)
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
        // Si le nom d'une forme est donnée plus de deux fois, elle ne sera supprimée qu'une seule fois
        for(unsigned int i = 1; i < arguments.size(); ++i)
        {
            if(!geoEdit.FormeExiste(arguments[i]))
            {
#ifdef VERBOSE
                cout<<ERREUR<<endl;
                cout<<COMMENTAIRES<<"Forme "<<arguments[i]<<" inconnue!"<<endl;
#endif
                return ERR_UNKNOWN_NAME;
            }
        }

        // Sauvegarde puis suppression des formes
        for(unsigned int i = 1; i<arguments.size(); ++i)
        {
            Forme *f = geoEdit.GetForme(arguments[i]);
            if(f != NULL)
            {
                // Casse le lien que la Forme a avec les Selections
                geoEdit.CasserLien(f);

                /* Dans le cas ou c'est une selection, on va aussi recuperer les Formes qu'elle
                contient pour les mettres dans le vecteur de Formes supprimées
                 */
                vector<Forme *> formesAdeplacer = f->GetFormesSelectionnees();
                deplacerFormes(formesAdeplacer);

                // on vide la Forme
                f->Supprimer();
                // on met la Forme dans le vecteur des Formes supprimées
                formesSupprimees.push_back(f);

                //On supprime la Forme de la MAP après l'avoir sauvegarder
                geoEdit.EraseForme(arguments[i]);
            } // fin if
        } // Fin for
#ifdef VERBOSE
        if(afficheMsg)
           cout<<OK<<endl;
#endif
        return GOOD;

    }
} //----- Fin de Execute

CODERETOUR CmdDelete::UnExecute(bool afficheMsg)
{
    for(unsigned int i=0; i<formesSupprimees.size(); ++i)
    {
        // on remet toutes les formes qu'on avait supprimées
        if(formesSupprimees[i]!=NULL)
            geoEdit.Ajouter(formesSupprimees[i]->GetNom(), formesSupprimees[i]);
    }
    formesSupprimees.clear();

    return GOOD;
} //----- Fin de UnExecute



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

} //----- Fin de CmdDelete


//------------------------------------------------------- Méthodes privées
void CmdDelete::deplacerFormes(vector<Forme *> &vector1) {
    for(unsigned int i = 0; i<vector1.size(); ++i)
    {
        if(vector1[i]!=NULL)
        {
            formesSupprimees.push_back(vector1[i]);
            geoEdit.EraseForme(vector1[i]->GetNom());
        }
    }
}



// ------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées