/*************************************************************************
                           Modele  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Modele> (fichier Modele.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Modele.h"
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
Modele Modele::m_modele=Modele();

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


Modele::Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Modele>" << endl;
#endif
} //----- Fin de Modele


Modele::~Modele ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Modele>" << endl;
#endif
    // Libération des formes
    for(Formes::iterator it = formes.begin(); it != formes.end(); it++)
    {
        delete it->second;
    }

    liberePileUndo();
    liberePileRedo();



} //----- Fin de ~Modele


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
Modele &Modele::Instance() {
    return m_modele;
}

void Modele::Ajouter(string name, Forme *uneForme)
{
    formes.insert(make_pair(name, uneForme));
}

void Modele::Afficher(ostream & flux) const
{
    for(Formes::const_iterator it = formes.begin(); it != formes.end(); it++)
    {
        it->second->Afficher(flux);
    }
}

void Modele::Sauvegarder(ofstream& file)const
{
    Formes::const_iterator it;
    for(it = formes.begin(); it != formes.end(); it++)
    {
        it->second->Afficher(file);
    }
}

void Modele::Empiler(Commande *uneCommande)
{

#ifdef MAP
cout <<"Empilement de la commande "<<endl;
#endif
    cmdToUndo.push(uneCommande);

    liberePileRedo(); // vide la pile des Redo


#ifdef MAP
    cout<<" Taille de la pile "<<cmdToUndo.size()<<endl;
#endif
}

bool Modele::FormeExiste(string nom) const {
    return formes.find(nom) != formes.end();
}

Forme *Modele::GetForme(string name)const  {
    if(FormeExiste(name))
    {
        return formes.find(name)->second;
    }
    else
    {
        return NULL;
    }
}

void Modele::Undo() {
    if(!cmdToUndo.empty())
    {
        cmdToRedo.push(cmdToUndo.top());// met la commande sur les commandes à Redo
        cmdToUndo.top()->UnExecute(); // Annule la commande
        cmdToUndo.pop(); // Depilement
#ifdef VERBOSE
           cout<<OK<<endl;
#endif
    }
}

void Modele::Redo()
{
    if(!cmdToRedo.empty())
    {
        cmdToRedo.top()->Execute(false); // Execution
        cmdToUndo.push(cmdToRedo.top()); //Empilement sur Undo
        cmdToRedo.pop(); // Depilement de Redo
#ifdef VERBOSE
           cout<<OK<<endl;
#endif

    }
}

void Modele::EraseForme(string name)
{
    formes.erase(name);
}

void Modele::liberePileUndo() {
    while(!cmdToUndo.empty())
    {
        delete cmdToUndo.top();
        cmdToUndo.pop();
    }
}

void Modele::liberePileRedo() {
    while(!cmdToRedo.empty())
    {
        delete cmdToRedo.top();
        cmdToRedo.pop();
    }
}

vector<Forme *> Modele::GetFormeSelection(Point p1, Point p2) const
{
    vector<Forme *> formesSelectionnees;
    Formes::const_iterator it;
    for(it=formes.begin(); it!=formes.end(); it++)
    {
        if(it->second->InclusDans(p1, p2))
        {
            formesSelectionnees.push_back(it->second);
        }
    }
    return formesSelectionnees;
}

void Modele::CasserLien(const Forme *uneForme) {
    /* récuperation de la liste des Selection à qui on doit signaler qu'une
     de leur forme vient d'etre supprimée */
    vector<string> lesSelections = uneForme->GetSelections();
    string nomForme = uneForme->GetNom();

    // parcours des selections dans lesquelles la forme se trouvait
    for(unsigned int i =0; i<lesSelections.size(); ++i)
    {
        Forme * f = GetForme(lesSelections[i]);
        f->CasserLienVersForme(nomForme);
    }
}

Formes Modele::GetMAPFormes() const {
    return formes;
}

void Modele::Clear() {
    formes.clear();
}

void Modele::SetMAP(Formes &uneMap) {
    formes = uneMap;
}
