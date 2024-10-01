//
// Created by andre on 18/09/2024.
#pragma once
#include <iostream>
#include <string>
#include <cstring>

namespace MATH {

    class FractionException {
        char info[256];
    public:
        FractionException(const char* str) {
            strcpy(info, str);
        }

        const char* getInfo() const {
            return info;
        }
    };


    class Fraction {
    private :
        int numerateur;
        int denominateur;
        void simplification();

    public :

        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(int numerator);

        ~Fraction();

         int getNumerator() {
            return numerateur;
        }
        int getDenominator() {
            return denominateur;
        }

        void setNumerator(int numerator);

        void setDenominator(int denominator);

        void setFraction(int num, int den);

        Fraction somme(const Fraction& f1, const Fraction& f2);
        Fraction somme(const Fraction& f);

        Fraction operator+(const Fraction &autre) const;

        Fraction operator+(int entier) const;

        Fraction &operator++();

        Fraction operator++(int);

        friend std::ostream &operator<<(std::ostream &out, const Fraction &f);

        static int pgcd(int a, int b);
    };
}
