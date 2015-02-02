#include <iostream>
using namespace std;

const int taille = 100;
int main()
{
    for(int i = 0; i < taille; i++)
    {
        cout << "R R" << i << " " << i-1 << " " << i-1 << " " << i+1 << " " << i+1 << endl;
    }
    
    for(int i = 0; i < taille; i++)
    {
        cout << "DELETE R" << i << endl;
    }

    for(int i = 0; i < taille; i++)
    {
        cout<<"UNDO"<<endl;
    }


    cout << "EXIT" << endl;
    return 0;
}
