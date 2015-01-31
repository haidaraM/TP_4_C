/*************************************************************************
                           CmdMove  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <CmdMove> (fichier CmdMove.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CmdMove.h"
#include "Modele.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CmdMove::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


CmdMove::CmdMove (string name ):Commande(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CmdMove>" << endl;
#endif
} //----- Fin de CmdMove


CmdMove::~CmdMove ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CmdMove>" << endl;
#endif


} //----- Fin de ~CmdMove

CODERETOUR CmdMove::Execute()
{
    // découpage de la commande
    vector<string> arguments = decoupe();
    if(arguments.size() != 4 || !allDigit(arguments))
    {
        AfficherErreurCommande();
        return ERR_SYNTAXE;
    }
    else
    {

        string name = arguments[1];
        long dx = strtol(arguments[2].c_str(), NULL, 10);
        long dy = strtol(arguments[3].c_str(), NULL, 10);

        if(geoEdit.FormeExiste(name))
        {
           // cout<<"1 : Appel de CmdMove::Execute() "<<endl;
            geoEdit.GetForme(name)->Deplacer(dx, dy);
            return GOOD;
        }
        else
            return ERR_UNKNOWN_NAME;
    }

}//----- Fin de Execute

CODERETOUR CmdMove::UnExecute()
{
   // cout<<"Appel de CmdMove::UnExecute() "<<endl;
    vector<string> arguments = decoupe();
    string name = arguments[1];
    long dx = strtol(arguments[2].c_str(), NULL, 10);
    long dy = strtol(arguments[3].c_str(), NULL, 10);

    geoEdit.GetForme(name)->Deplacer(-dx, -dy);

    return GOOD;
} //----- Fin de UnExecute
