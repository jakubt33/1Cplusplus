#ifndef LICZBAZESPOLONA_H
#define LICZBAZESPOLONA_H
#pragma once
#include <iostream>
#include <cmath>

//dopisac zabezpieczenie przed dzieleniem przez 0

using namespace std;
class LiczbaZespolona
{
    public:
        LiczbaZespolona(double re = 0, double im = 0);
        void modul();
        void setIm(double);
        void setRe(double);
        void wyswietl();

        LiczbaZespolona operator+ (const LiczbaZespolona &b);
        LiczbaZespolona operator- (const LiczbaZespolona &b);
        LiczbaZespolona operator* (const LiczbaZespolona &b);
        LiczbaZespolona operator/ (const LiczbaZespolona &b);

        void operator+= (const LiczbaZespolona &b);
        void operator-= (const LiczbaZespolona &b);
        void operator*= (const LiczbaZespolona &b);
        void operator/= (const LiczbaZespolona &b);

        friend ostream &operator<< (ostream &str, const LiczbaZespolona &b);

        virtual ~LiczbaZespolona();
    protected:
    private:
        double re, im, mod;
};

#endif // LICZBAZESPOLONA_H
