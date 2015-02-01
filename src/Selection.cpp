/*************************************************************************
                          Selection  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Selection> (fichier Selection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Selection::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Selection::Afficher(ostream & flux)const
{
	//on n'affiche pas les selections
}

void Selection::Supprimer()
{	
	for(unsigned int i = 0; i <contenues.size();++i)
	{
        if(contenues[i] != NULL)
			contenues[i]->Supprimer();
	}
}

void Selection::Deplacer(long abs, long ord)
{
	for(unsigned int i = 0; i < contenues.size();++i)
	{
        if(contenues[i] != NULL)
        {
#ifdef MAP
            cout<<"Appel de Selection::Deplacer(long,long) "<<endl;
            cout<<"Addresse de l'objet en deplacement : "<<contenues[i]<<endl;
#endif
            contenues[i]->Deplacer(abs, ord);
        }
    }
}

bool Selection::InclusDans(Point p1, Point p2)const
{
	// Une selection ne peut pas être selectionnée donc pas de vérification d'inclusion
    // Dans le futur il suffira de modifier cette méthode si on souhaite cette fonctionnalité
    return false;
}


//-------------------------------------------- Constructeurs - destructeur

Selection::Selection (string name, vector <Forme*>& f): Forme(name), contenues(f)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
    majFormeSelectionnees();

} //----- Fin de Selection


Selection::~Selection ( )
// Algorithme : Aucun! L'application principale se chargera de liberer la mémoire
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif

} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

void Selection::majFormeSelectionnees() {
    for(unsigned int i=0; i<contenues.size(); i++)
    {
        contenues[i]->AjouteSelection(nom);
    }

}

void Selection::CasserLienVersForme(string nomForme) {
    bool ok = false;
    for(unsigned int i=0; i<contenues.size() && !ok; ++i)
    {
        if(contenues[i]!= NULL && contenues[i]->GetNom() == nomForme)
        {
            contenues[i] = NULL;
            ok = true;
        }
    }
}

vector<Forme *> Selection::GetFormesSelectionnees() const {
    return contenues;
}
