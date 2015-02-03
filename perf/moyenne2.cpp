#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	float somme = 0;
	float temps;
	int nbLigne = 0;
	ifstream file(argv[1]);
	if(file.good())
	{
		while(file>>temps) 
		{
			nbLigne++;
		    somme += temps;
		}
		if(nbLigne != 0)
			cout <<"Moyenne : "<<somme/nbLigne<<endl;
	}
	else
	{
		cout<<"Probleme de lecture du fichier"<<endl;
	}
	return 0;
}
