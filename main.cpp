#include <iostream>
#include "macierz.h"

using namespace std;

int main()
{
    Macierz i(2,3);
    //Macierz<double> j(2,3);
    //Macierz<double> k(3,2);
    try
    {
        Macierz macierz(-1,0);
        cout<<macierz<<endl;
    }
    catch(const char * err)
    {
        cout<<"Hapłem wyjątka o numerze: ";
        cout<<err<<endl;
    }
    return 0;
}
