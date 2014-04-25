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
        cout<<a+b<<endl;
        cout<<a*b<<endl;
        cout<<a*c<<endl;
        //c/=a;
        //cout<<c<<endl;
        //c*=a;
        //cout<<c<<endl;
        c+=a;
        cout<<c<<endl;
        c-=a;
        cout<<c<<endl;
       // */
        /*
        Macierz<double> i(3,2); //(m,n)
        Macierz<double> j(3,2);
        Macierz<double> k(3,2);
        try
        {
            Macierz<double> macierz(-1,0);
            cout<<macierz<<endl;
        }
        catch(const char * err)
        {
            cout<<err<<endl; //to printuje dupa
        }
        j.wypelnijLosowo();
        i.wypelnijJedynkami();
        cout<<j<<endl<<i<<endl;
        k.wypelnijJedynkami();
      //  cout<<i+j<<endl;
       // cout<<i-j+i<<endl;
        i=j-i;
        cout<<i<<endl;
        */
    }
    catch(const char *err)
    {
       cout<<err<<endl;
    }
}
