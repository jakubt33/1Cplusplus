#ifndef MACIERZ_H
#define MACIERZ_H

#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Macierz
{
private:
    double **tablica;
    int m, n;
public:
    void macierz_losowa();
    friend ostream &operator<< (ostream &str, const Macierz &a);

    Macierz(int m=1, int n=1)
    {
        this->m = m;
        this->n = n;
        if(m<=0 || n<=0)
        {
            char *x = "dupa" ;
            throw x;
        }
        tablica = new double *[m];
        for(int i=0; i<m; i++)
            tablica[i] = new double [n];
    }
    virtual ~Macierz()
    {
        for(int x=0;x<this->n;x++)
            delete []tablica[x];
            delete []tablica;
    }
protected:
};

ostream &operator<< (ostream &str, const Macierz &a)
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
void Macierz::macierz_losowa()
{
    srand(time(NULL));
    for(int x=0; x<this->m; x++)
        for(int y=0; y<this->n; y++)
            this->tablica[x][y] = rand()%10;

}
#endif // MACIERZ_H
