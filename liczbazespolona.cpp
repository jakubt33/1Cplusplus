#include "liczbazespolona.h"

using namespace std;

LiczbaZespolona::LiczbaZespolona(double re, double im): re(re), im(im)
{
}

LiczbaZespolona::~LiczbaZespolona()
{
}

void LiczbaZespolona::modul()
{
    this->mod = sqrt( pow(this->re, 2) + pow( this->im, 2 ) );
}

void LiczbaZespolona::setIm(double im)
{
    this->im = im;
}

void LiczbaZespolona::setRe(double re)
{
    this->re = re;
}

void LiczbaZespolona::wyswietl()
{
    LiczbaZespolona::modul();
    cout<<this->re;
    if(this->im>=0) cout<<"+";
    cout<<this->im<<"i ("<<this->mod<<")"<<endl;
}

LiczbaZespolona LiczbaZespolona::operator+ (const LiczbaZespolona &b)
{
    return LiczbaZespolona(re+b.re, im+b.im);
}

LiczbaZespolona LiczbaZespolona::operator- (const LiczbaZespolona &b)
{
    return LiczbaZespolona(re-b.re, im-b.im);
}

LiczbaZespolona LiczbaZespolona::operator* (const LiczbaZespolona &b)
{
    return LiczbaZespolona(re*b.re-im*b.im, re*b.im+b.re*im);
}

LiczbaZespolona LiczbaZespolona::operator/ (const LiczbaZespolona &b)
{
    if(b.re == 0 && b.im == 0) throw "nie dziel przez zero";
    else return LiczbaZespolona((re*b.re)/(b.re*b.re+b.im*b.im), (im*b.re-re*b.im)/(b.re*b.re+b.im*b.im));
}

void LiczbaZespolona::operator+= (const LiczbaZespolona &b)
{
     re+=b.re;
     im+=b.im;
}

void LiczbaZespolona::operator-= (const LiczbaZespolona &b)
{
     re-=b.re;
     im-=b.im;
}

void LiczbaZespolona::operator*= (const LiczbaZespolona &b)
{
    double re_kopia = (re*b.re-im*b.im);
    im = re*b.im+b.re*im;
    re = re_kopia;
}

void LiczbaZespolona::operator/= (const LiczbaZespolona &b)
{
    if(b.re == 0 && b.im == 0) throw "nie dziel przez 0";
    else
    {
        double re_kopia = (re*b.re+im*b.im)/(b.re*b.re+b.im*b.im);
        im=(im*b.re-re*b.im)/(b.re*b.re+b.im*b.im);
        re = re_kopia;
    }
}

ostream &operator<< (ostream &str, const LiczbaZespolona &b)
{
    str<<b.re;
    if(b.im>=0) str<<"+";
    str<<b.im<<"i";
    return str;
}
