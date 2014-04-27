#ifndef MACIERZ_H
#define MACIERZ_H

#pragma once
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
    Macierz(int m=1, int n=1):m(m),n(n) {
        if(m<=0 || n<=0) throw "zły rozmiar macierzy";
        nowa_tablica();
    }
    Macierz(const Macierz &macierz):m(macierz.m), n(macierz.n) {
        nowa_tablica();

        for(int x=0; x<m; x++)
            for(int y=0; y<n; y++)
                tablica[x][y] = macierz.tablica[x][y];
    }

    void macierzJednostkowa();
    void nowa_tablica();
    void usun();
    void wypelnijJedynkami();
    void wypelnijLosowo();
    void wypelnijZerami();

    Macierz<T> operator+ (const Macierz &b);
    Macierz<T> operator- (const Macierz &b);
    Macierz<T> operator* (const Macierz &b);

    void operator+= (const Macierz &b);
    void operator-= (const Macierz &b);
    void operator*= (const Macierz &b);

    void operator= (const Macierz &b);

    friend ostream &operator<< <>(ostream &str, const Macierz<T> &a);

    virtual ~Macierz() {
        usun();
    }
protected:
};

template <class T>
void Macierz<T>::macierzJednostkowa()
{
    if(m!=n) throw "macierz musi być kwadratowa";
    wypelnijZerami();
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            if(x==y) tablica[x][y] = 1;
}

template <class T>
void Macierz<T>::nowa_tablica()
{
    tablica = new T *[m];
    for(int i=0; i<m; i++)
        tablica[i] = new T [n];

    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            this->tablica[x][y] = 0;
}

template <class T>
void Macierz<T>::usun()
{
    for(int x=0; x<m; x++)
        delete []tablica[x];
    delete []tablica;
}

template <class T>
void Macierz<T>::wypelnijJedynkami()
{
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            tablica[x][y] = 1;
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
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            tablica[x][y] = 0;
}

template <class T>
Macierz<T> Macierz<T>::operator+ (const Macierz &b)
{
    if(m != b.m || n != b.n) throw "nie poprawne wymiary macierzy";
    Macierz temp(m,n);
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            temp.tablica[x][y] = tablica[x][y] + b.tablica[x][y];
    return temp;
}

template <class T>
Macierz<T> Macierz<T>::operator- (const Macierz &b)
{
    if(m != b.m || n != b.n) throw "nie poprawne wymiary macierzy";
    Macierz temp(m,n);
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            temp.tablica[x][y] = tablica[x][y] - b.tablica[x][y];
    return temp;
}

template <class T>
Macierz<T> Macierz<T>::operator*(const Macierz &b)
{
    if(n != b.m) throw "nie poprawne wymiary macierzy";
    else
    {
        Macierz kopia (m,b.n);
        for(int x=0; x<m; x++)
        {
            for(int y=0; y<b.n; y++)
            {
                T temp = 0;
                for(int k=0;k<n;k++)
                {
                    temp += tablica[x][k] * b.tablica[k][y];
                }
                kopia.tablica[x][y] = temp;
             }
        }
    return kopia;
    }
}

template <class T>
void Macierz<T>::operator+= (const Macierz &b)
{
    if(m != b.m || n != b.n) throw "nie poprawne wymiary macierzy";
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            tablica[x][y] += b.tablica[x][y];
}

template <class T>
void Macierz<T>::operator-= (const Macierz &b)
{
    if(m != b.m || n != b.n) throw "nie poprawne wymiary macierzy";
    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            tablica[x][y] -= b.tablica[x][y];
}

template <class T>
void Macierz<T>::operator*= (const Macierz &b)
{
    if(n != b.m) throw "nie poprawne wymiary macierzy";
    else
    {
        Macierz kopia = *this;
        usun();
        int temp_n = n;
        n=b.n;
        nowa_tablica();
        for(int x=0; x<m; x++)
        {
            for(int y=0; y<n; y++)
            {
                T temp = 0;
                for(int k=0;k<temp_n;k++)
                {
                    temp += kopia.tablica[x][k] * b.tablica[k][y];
                }
                tablica[x][y] = temp;
             }
        }
        cout<<endl;
    }
}

template <class T>
void Macierz<T>::operator= (const Macierz &b)
{
    usun();
    m = b.m;
    n = b.n;
    nowa_tablica();

    for(int x=0; x<m; x++)
        for(int y=0; y<n; y++)
            this->tablica[x][y] = b.tablica[x][y];
}

template <class T>
ostream &operator<< (ostream &str, const Macierz<T> &a)
{
    str<<endl;
    for(int x=0; x<a.m;x++)
        {
            for(int y=0; y<a.n; y++)
                {
                    str<<a.tablica[x][y]<<" ";
                }
            str<<endl;
        }
    return str;
}

#endif // MACIERZ_H
