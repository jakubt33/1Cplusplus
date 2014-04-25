#include "liczbazespolona.h"

using namespace std;

LiczbaZespolona::LiczbaZespolona(double re, double im): re(re), im(im)
{
}

LiczbaZespolona::~LiczbaZespolona()
{
}
void LiczbaZespolona::setRe(double re)
{
    this->re = re;
}
void LiczbaZespolona::setIm(double im)
{
    this->im = im;
}
void LiczbaZespolona::wyswietl()
{
    LiczbaZespolona::modul();
    cout<<this->re;
    if(this->im>=0) cout<<"+";
    cout<<this->im<<"i ("<<this->mod<<")"<<endl;
}
void LiczbaZespolona::modul()
{
    this->mod = sqrt( pow(this->re, 2) + pow( this->im, 2 ) );
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
    return LiczbaZespolona(re*b.re+im*b.im, re*b.im+b.re*im);
}
LiczbaZespolona LiczbaZespolona::operator/ (const LiczbaZespolona &b)
{
    if(b.re == 0 && b.im == 0)
        throw "nie dziel przez zero";

    return LiczbaZespolona((re*b.re)/(b.re*b.re+b.im*b.im), (im*b.re-re*b.im)/(b.re*b.re+b.im*b.im));
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
//void LiczbaZespolona::operator*= (const LiczbaZespolona &b)
//{
 //   re=re*b.re+im*b.im;
  //  im=re*b.im+b.re*im;
//}


ostream &operator<< (ostream &str, const LiczbaZespolona &b)
{
    str<<b.re;
    if(b.im>=0) str<<"+";
    str<<b.im<<"i"<<endl;
    return str;
}
