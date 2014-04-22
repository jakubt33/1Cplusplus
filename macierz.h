#ifndef MACIERZ_H
#define MACIERZ_H

#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
template <class T>
class Macierz
{
private:
    T **tablica;
    int m, n;
public:
    void wypelnijLosowo();
    void wypelnijZerami();
    void wypelnijJedynkami();
    friend ostream &operator<< (ostream &str, const Macierz<T> &a) {
    for(int x=0; x<a.m;x++)
        {
            for(int y=0; y<a.n; y++)
                {
                    cout<<a.tablica[x][y]<<" ";
                }
            cout<<endl;
        }
    return str;
    }

    Macierz(int m=1, int n=1)
    {
        this->m = m;
        this->n = n;
        if(m<=0 || n<=0)
        {
            char *x = "dupa" ;
            throw x;
        }
        tablica = new T *[m];
        for(int i=0; i<m; i++)
            tablica[i] = new T [n];
    }
    virtual ~Macierz()
    {
        for(int x=0;x<this->n;x++)
            delete []tablica[x];
            delete []tablica;
    }
protected:
};
/*
ostream &operator<< (ostream &str, const Macierz<T> &a)
{
    for(int x=0; x<a.m;x++)
        {
            for(int y=0; y<a.n; y++)
                {
                    cout<<a.tablica[x][y]<<" ";
                }
            cout<<endl;
        }
    return str;
}
*/
template <class T>
void Macierz<T>::wypelnijLosowo()
{
    srand(time(NULL));
    for(int x=0; x<this->m; x++)
        for(int y=0; y<this->n; y++)
            this->tablica[x][y] = rand()%10;

}
template <class T>
void Macierz<T>::wypelnijZerami()
{
    srand(time(NULL));
    for(int x=0; x<this->m; x++)
        for(int y=0; y<this->n; y++)
            this->tablica[x][y] = 0;

}
template <class T>
void Macierz<T>::wypelnijJedynkami()
{
    srand(time(NULL));
    for(int x=0; x<this->m; x++)
        for(int y=0; y<this->n; y++)
            this->tablica[x][y] = 1;

}

#endif // MACIERZ_H
