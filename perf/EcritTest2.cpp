#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[])
{   
    int taille = atoi(argv[1]);
    
    
    for(int i = 0; i < taille; i++)
    {
        cout << "C C" << i << " " << i << " " << i << " " << 1 << endl;
    }
   /* cout << "CLEAR" << endl;
    for(int i = 0; i < taille; i++)
    {
        cout << "UNDO" << endl;
        cout << "MOVE C" << i << " 3 3" << endl;
    }
    cout << "S S3 -1 -1 200000 200000" << endl;
    cout << "S S1 200000 200000 900000 900000" << endl;
    cout << "S S2 900000 900000 1000001 1000001" << endl;
    cout << "DELETE C200 S3 C33 S1 C42 S2 C400" << endl;
    cout << "UNDO" << endl;
    cout << "REDO" << endl;
    cout << "LIST" << endl; */
    //cout << "EXIT" << endl; 
    return 0;
}
