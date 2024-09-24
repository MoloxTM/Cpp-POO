#include <iostream>
#include "fraction.h"
using namespace std;

namespace MATH {
    int Fraction::pgcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Fraction::Fraction() : numerateur(0), denominateur(1) {}
    Fraction::Fraction(int num = 0, int den = 1) : numerateur(num), denominateur(den) {
        if (den == 0) {
            cerr << "Erreur : Le dénominateur ne peut pas être zéro. Défini à 1." << endl;
            denominateur = 1;
        }
        simplification();
    }
    Fraction::Fraction(int num = 0) {
        setFraction(num, 1);
        simplification();
    }

    Fraction::~Fraction() {
        cout << "Destruction de Fraction à l'adresse :" << this << endl;
    }

    void Fraction::simplification() {
        int diviseur = pgcd(numerateur, denominateur);
        if(diviseur == 0) {
            diviseur = 1;
        }
        numerateur /= diviseur;
        denominateur /= diviseur;
    }

    void Fraction::setNumerator(int numerator) {
        numerateur = numerator;
    }

    void Fraction::setDenominator(int denominator) {
        if(denominator == 0) {
            cerr << "Erreur : Le dénominateur ne peut pas être zéro. Défini à 1." << endl;
            denominator = 1;
        }
        denominateur = denominator;
    }

    void Fraction::setFraction(int num, int den) {
        numerateur = num;
        if(den == 0) {
            cerr << "Erreur : Le dénominateur ne peut pas être zéro. Défini à 1." << endl;
            den = 1;
        }
        denominateur = den;
        simplification();
    }

    Fraction Fraction::somme(const Fraction& f1, const Fraction& f2) {
        Fraction somme;
        somme.numerateur = (f1.numerateur * f2.denominateur) + (f1.denominateur * f2.numerateur);
        somme.denominateur = f1.denominateur * f2.denominateur;
        somme.simplification();
        return somme;
    }

    Fraction Fraction::somme(const Fraction& f) {
        Fraction somme;
        somme.numerateur = (numerateur * f.denominateur) + (denominateur * f.numerateur);
        somme.denominateur = f.denominateur * denominateur;
        somme.simplification();
        return somme;
    }

    Fraction Fraction::operator+(const Fraction& autre) const {
        int num = numerateur * autre.denominateur + autre.numerateur * denominateur;
        int den = denominateur * autre.denominateur;
        return Fraction(num, den);
    }

    Fraction Fraction::operator+(int entier) const {
        int num = numerateur + entier * denominateur;
        return Fraction(num, denominateur);
    }

    Fraction Fraction::operator+(int entier, const Fraction& f) {
        return f + entier;
    }

    Fraction& Fraction::operator++() {
        numerateur += denominateur;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        numerateur += denominateur;
        return temp;
    }

    ostream& Fraction::operator<<(ostream& out, const Fraction& f) {
        out << f.numerateur << "/" << f.denominateur;
        return out;
    };


    Fraction somme(Fraction& f1, Fraction& f2) {
        Fraction somme;
        somme.setNumerator((f1.getNumerator()* f2.getDenominator()) + (f1.getDenominator() * f2.getNumerator()));
        somme.setDenominator(f1.getDenominator() * f2.getDenominator());
        return somme;
    }


}
