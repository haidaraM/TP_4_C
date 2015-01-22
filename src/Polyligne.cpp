/*************************************************************************
                           Polyligne  -  description
                             -------------------
*************************************************************************/

//---------- R�alisation de la classe <Polyligne> (fichier Polyligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s

//----------------------------------------------------- M�thodes publiques
// type Polyligne::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void Polyligne::Afficher()const
{

}

//------------------------------------------------- Surcharge d'op�rateurs
Polyligne & Polyligne::operator = ( const Polyligne & unPolyligne )
{
}


//-------------------------------------------- Constructeurs - destructeur
Polyligne::Polyligne ( const Polyligne & unPolyligne )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyligne>" << endl;
#endif
} 


Polyligne::Polyligne ( )

{
#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
}


Polyligne::~Polyligne ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
}
