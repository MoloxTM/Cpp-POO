#include <iostream>
using namespace std;

namespace MATH {
    class Fraction {
    private:
        int numerateur;
        int denominateur;

        int pgcd(int a, int b) const {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

    public:
        Fraction() : numerateur(0), denominateur(1) {}
        Fraction(int num, int den) : numerateur(num), denominateur(den) {
            if (den == 0) {
                cout << "Erreur : Le dénominateur ne peut pas être zéro. Défini à 1." << endl;
                denominateur = 1;
            }
        }

        ~Fraction() {
            cout << "Destruction de Fraction à l'adresse " << this << endl;
        }

        void simplifier() {
            int diviseur = pgcd(numerateur, denominateur);
            numerateur /= diviseur;
            denominateur /= diviseur;
        }

        Fraction operator+(const Fraction& autre) const {
            int num = numerateur * autre.denominateur + autre.numerateur * denominateur;
            int den = denominateur * autre.denominateur;
            return Fraction(num, den);
        }

        Fraction operator+(int entier) const {
            int num = numerateur + entier * denominateur;
            return Fraction(num, denominateur);
        }

        friend Fraction operator+(int entier, const Fraction& f) {
            return f + entier;
        }

        Fraction& operator++() {
            numerateur += denominateur;
            return *this;
        }

        Fraction operator++(int) {
            Fraction temp = *this;
            numerateur += denominateur;
            return temp;
        }

        friend ostream& operator<<(ostream& out, const Fraction& f) {
            out << f.numerateur << "/" << f.denominateur;
            return out;
        }
    };
}
