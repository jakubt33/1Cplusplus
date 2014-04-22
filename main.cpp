#include <iostream>
#include "macierz.h"

using namespace std;

int main()
{
    try
    {

        /*LiczbaZespolona a(1,2);
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
        */

        Macierz<double> i(2,3);
        Macierz<double> j(2,3);
        Macierz<double> k(3,2);
        try
        {
            Macierz<double> macierz(-1,0);
            cout<<macierz<<endl;
        }
        catch(const char * err)
        {
            cout<<err<<endl;
        }
        i.wypelnijJedynkami();
        j.wypelnijZerami();
        k.wypelnijLosowo();
        //cout<<i+j<<endl;
        //cout<<i-j+i<<endl;
        //i=j;
        //j+=i;
        cout<<i<<endl<<j<<endl<<k;
    }
    catch(const char *err)
    {
            cout<<err<<endl;
    }
}
