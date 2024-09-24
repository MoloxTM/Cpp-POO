//
// Created by andre on 18/09/2024.
#pragma once
#include <iostream>

namespace MATH {
    class Fraction {
    private :
        int numerator;
        int denominator;
        int pgcd(int a, int b);

    public :
        Fraction(int numerator, int denominator);
        Fraction();

        ~Fraction();

         int getNumerator() {
            return numerator;
        }
        int getDenominator() {
            return denominator;
        }

        void setNumerator(int numerator);

        void setDenominator(int denominator);

        void setFraction(int num, int den);

        void simplification() {
            int p = pgcd(numerator, denominator);
            numerator /= p;
            denominator /= p;
            if(denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }

        Fraction somme(Fraction f, Fraction g);

    };
}
