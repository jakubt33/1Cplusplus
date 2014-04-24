#ifndef MACIERZ_H
#define MACIERZ_H

#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
template <class T>
class Macierz;
template <class T>
ostream &operator<< (ostream &str, const Macierz<T> &);


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
    void nowa_tablica(int, int);
    void usun(int);


    Macierz<T> &operator+= (const Macierz &b);
    Macierz<T> &operator-= (const Macierz &b);
    //iczbazespolona operator- (const liczbazespolona &b);
    //liczbazespolona operator* (const liczbazespolona &b);
    friend ostream &operator<< <>(ostream &str, const Macierz<T> &a);


    Macierz(int m=1, int n=1)
    {
        this->m = m;
        this->n = n;
        if(m<=0 || n<=0)
        {
            throw "dupa";
        }
        nowa_tablica(m,n);
    }

    Macierz(const Macierz& macierz)
    {
        m = macierz.m;
        n = macierz.n;
        nowa_tablica(m,n);

        for(int x=0; x<m; x++)
            for(int y=0; y<n; y++)
                tablica[x][y] = macierz.tablica[x][y];
    }
    virtual ~Macierz()
    {
        usun(n);
    }

protected:
};
template <class T>
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

template <class T>
Macierz<T> &Macierz<T>::operator+= (const Macierz &b)
{
    int x, y;
    for(x=0; x<n; x++)
        for( y=0; y<m; y++)
            this->tablica[x][y] += b.tablica[x][y];
    cout<<*this<<endl;

    return *this;
}

template <class T>
Macierz<T> &Macierz<T>::operator-= (const Macierz &b)
{
    int x, y;
    for(x=0; x<n; x++)
        for( y=0; y<m; y++)
            this->tablica[x][y] -= b.tablica[x][y];
    cout<<*this<<endl;

    return *this;
}
template <class T>
void Macierz<T>::nowa_tablica(int m, int n)
{
    tablica = new T *[m];
    for(int i=0; i<m; i++)
        tablica[i] = new T [n];
}

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

template <class T>
void Macierz<T>::usun(int n)
{
    cout<<"destrukcja!!"<<endl;
    for(int x=0; x<this->n; x++)
        delete []tablica[x];
    delete []tablica;
}


#endif // MACIERZ_H
