/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                : 16/01/2015
    copyright            : (C) 2015 par Emilien BAI - Mohamed HAIDARA - B3425
*************************************************************************/

//---------- Réalisation de la classe <Polyligne> (fichier Polyligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------- Méthodes publiques
// type Polyligne::Méthode ( liste de paramétres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Polyligne::Afficher(ostream & flux)const
{
	flux<<"PL "<<nom;
	long a;
	long o;
	for(vector<Point>:: const_iterator i = points.begin(); i != points.end();++i)
	{
			a = i->GetAbscisse();
			o = i->GetOrdonnee();
			flux<<" "<<a<<" "<<o;
	}
	flux<<"\r\n";
}

bool Polyligne::InclusDans(Point p1, Point p2) const
{
	long x;
	long y;
	long ap1 = p1.GetAbscisse();
	long ap2 = p2.GetAbscisse();
	long op1 = p1.GetOrdonnee();
	long op2 = p2.GetOrdonnee(); 
	for(vector<Point>:: const_iterator i = points.begin(); i != points.end();++i)
	{
			x = i->GetAbscisse();
			y = i->GetOrdonnee();
			
			if ((x < ap1 && x < ap2) || (x > ap1 && x > ap2) || (y < op1 && y < op2)
				|| (y > op1 && y > op2))
				{
					return false;
				}
	}
	return true;
}

void Polyligne::Deplacer(long x, long y)
{
	for(unsigned int i=0; i<points.size();++i)
	{
		points[i].Deplacer(x, y);
	}
}
//-------------------------------------------- Constructeurs - destructeur
Polyligne::Polyligne ( const Polyligne & unPolyligne ) : Forme(unPolyligne.nom),
                                                         points(unPolyligne.points)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyligne>" << endl;
#endif
} 


Polyligne::Polyligne (string name, vector <Point> p ):Forme(name), points(p)
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
