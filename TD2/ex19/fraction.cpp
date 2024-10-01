#include "fraction.h"
#include <iostream>

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

    // Constructeurs
    Fraction::Fraction() : numerateur(0), denominateur(1) {}

    Fraction::Fraction(int num, int den) : numerateur(num), denominateur(den) {
        if (den == 0) {
            throw FractionException("erreur : division par 0");
        }
        simplification();
    }

    Fraction::Fraction(int num) : numerateur(num), denominateur(1) {
        simplification();
    }

    // Destructeur
    Fraction::~Fraction() {
        cout << "Destruction de Fraction à l'adresse :" << this << endl;
    }

    // Méthode de simplification
    void Fraction::simplification() {
        int diviseur = pgcd(numerateur, denominateur);
        if (diviseur == 0) {
            diviseur = 1;
        }
        numerateur /= diviseur;
        denominateur /= diviseur;
    }

    // Setters
    void Fraction::setNumerator(int numerator) {
        numerateur = numerator;
    }

    void Fraction::setDenominator(int denominator) {
        if (denominator == 0) {
            cerr << "Erreur : Le dénominateur ne peut pas être zéro. Défini à 1." << endl;
            denominator = 1;
        }
        denominateur = denominator;
    }

    void Fraction::setFraction(int num, int den) {
        numerateur = num;
        if (den == 0) {
            cerr << "Erreur : Le dénominateur ne peut pas être zéro. Défini à 1." << endl;
            den = 1;
        }
        denominateur = den;
        simplification();
    }

    // Surcharge de l'opérateur +
    Fraction Fraction::operator+(const Fraction& autre) const {
        int num = numerateur * autre.denominateur + autre.numerateur * denominateur;
        int den = denominateur * autre.denominateur;
        return Fraction(num, den);
    }

    Fraction Fraction::operator+(int entier) const {
        int num = numerateur + entier * denominateur;
        return Fraction(num, denominateur);
    }


    // Surcharge de l'opérateur préfixé ++
    Fraction& Fraction::operator++() {
        numerateur += denominateur;
        return *this;
    }

    // Surcharge de l'opérateur postfixé ++
    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        numerateur += denominateur;
        return temp;
    }

    // Surcharge de l'opérateur <<
    std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.numerateur << "/" << f.denominateur;
        return out;
    }

    // Méthode pour sommer deux fractions
    Fraction Fraction::somme(const Fraction& f1, const Fraction& f2) {
        Fraction somme = Fraction();
        somme.setNumerator((f1.numerateur * f2.denominateur) + (f1.denominateur * f2.numerateur));
        somme.setDenominator(f1.denominateur * f2.denominateur);
        somme.simplification();
        return somme;
    }
}
