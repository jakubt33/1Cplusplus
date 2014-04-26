#include <iostream>
#include "macierz.h"
#include "liczbazespolona.h"

using namespace std;

int main()
{
    try
    {

        LiczbaZespolona a(1,2);
        LiczbaZespolona b(0);
        LiczbaZespolona c(-1,-1);
        try{
            cout<<a/b<<endl;
        }catch(const char * err)
        {
           cout<<err<<endl;
        }
        //cout<<a+b<<endl;
        //cout<<a*b<<endl;
        //cout<<a*c<<endl;

        cout<<c<<endl;
        c*=a;
        cout<<c<<endl;
        c+=a;
        cout<<c<<endl;
        c-=a;
        cout<<c<<endl;

        Macierz<double> i(2,3);
        Macierz<double> j(2,3);
        Macierz<double> k(3,2);

        try
        {
            Macierz<double> macierz(-1,0);
            cout<<macierz<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        i.wypelnijJedynkami();
        j.wypelnijJedynkami();
        k.wypelnijJedynkami();
        cout<<i<<endl<<k<<endl;
        i*=k;
        cout<<i<<endl;
        //cout<<i-j+i<<endl;
        i=j;
        j+=i;

    }
    catch(const char *err)
    {
       cout<<err<<endl;
    }
}
