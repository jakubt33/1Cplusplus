#include <iostream>
#include "macierz.h"
#include "liczbazespolona.h"

using namespace std;

int main()
{
    try{
        LiczbaZespolona a(1,2);
        LiczbaZespolona b(0);
        LiczbaZespolona c(-1,-1);
        try{
            cout<<a/b<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        cout<<a+b<<endl;
        cout<<a*b<<endl;
        cout<<a*c<<endl;
        c/=a;
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
        try{
            Macierz<double> macierz(-1,0);
            cout<<macierz<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        i.wypelnijJedynkami();
        j.wypelnijJedynkami();
        k.wypelnijJedynkami();
        cout<<i+j<<endl;
        cout<<i-j+i<<endl;
        i=j;
        j+=i;
        cout<<j<<endl;
        cout<<i<<endl;
        cout<<i*k<<endl;
        try{
            cout<<k*k<<endl;
        }catch(const char * err)
        {
            cout<<err<<endl;
        }
        i.wypelnijLosowo();
        cout<<i;
	Macierz<LiczbaZespolona> l(3,3);
	l.wypelnijJedynkami();
	Macierz<LiczbaZespolona> m(3,3);
	m.macierzJednostkowa();
	l+=l;
	cout<<l*m<<endl;
    }catch(const char * err)
    {
        cout<<err<<endl;
    }

    return 0;
}

