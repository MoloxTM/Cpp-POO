#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
using namespace std;

namespace Set {
	// classe pour g�rer les exceptions dans le set
	class SetException {
	public:
		SetException(const string& i) :info(i) {}
		string getInfo() const { return info; }
	private:
		string info;
	};

	// caract�ristiques
	enum class Couleur { rouge, mauve, vert };
	enum class Nombre { un=1, deux=2, trois=3 };
	enum class Forme { ovale, vague, losange };
	enum class Remplissage { plein, vide, hachure };

	// conversion d'une caract�ristique en string
	string toString(Couleur c);
	string toString(Nombre v);
	string toString(Forme f);
	string toString(Remplissage v);

	// �criture d'une caract�ristique sur un flux ostream
	ostream& operator<<(ostream& f, Couleur c);
	ostream& operator<<(ostream& f, Nombre v);
	ostream& operator<<(ostream& f, Forme x);
	ostream& operator<<(ostream& f, Remplissage r);

	// listes contenant les valeurs possibles pour chacune des caract�ristiques
	extern std::initializer_list<Couleur> Couleurs;
	extern std::initializer_list<Nombre> Nombres;
	extern std::initializer_list<Forme> Formes;
	extern std::initializer_list<Remplissage> Remplissages;

	// affichage des valeurs possibles pour chaque caract�ristiques
	void printCouleurs(std::ostream& f = cout);
	void printNombres(std::ostream& f = cout);
	void printFormes(std::ostream& f = cout);
	void printRemplissages(std::ostream& f = cout);


	class Carte {

	private:
		Couleur couleur;
		Nombre nombre;
		Forme forme;
		Remplissage remplissage;

	public:

		Carte(Couleur c, Nombre n, Forme f, Remplissage r) : couleur(c), nombre(n), forme(f), remplissage(r) {}
		~Carte() = default;
		Carte(const Carte &c); //constructeur de recopie
		Carte &operator=(const Carte &c) = default;

		Couleur getCouleur() const {return couleur;}
		Nombre getNombre() const {return nombre;}
		Forme getForme() const {return forme;}
		Remplissage getRemplissage() const {return remplissage;}

	};

	ostream& operator<<(ostream& os, const Carte& carte);

	class Jeu {

	private:
		const Carte* cartes[81]{};
		size_t nbCarte = 81;

	public:

		Jeu();
		Jeu(const Jeu &j) = delete; //Ici on interdit la recopie
		Jeu& operator=(const Jeu& j) = delete; // On interdit l'opérateur d'affectation
		~Jeu();


		const Carte& getCarte(size_t i) const {
			if(i >= nbCarte) {
				throw SetException("Carte invalide");
			}
			return *cartes[i];
		}
		size_t getNbCarte() const {return 81;}
	};

	class Pioche {
	private:
		const Carte** cartes = nullptr;
		size_t nb = 0;


	public:
		explicit Pioche(const Jeu& jeu); //explicit va permettre d'empêcher la conversion d'un jeu en une pioche avec ce constructeur
		Pioche(const Pioche &jeu) = delete; //Interdiction recopie
		Pioche &operator=(const Pioche &jeu) = delete; //Interdiction affectation
		~Pioche();

		size_t getNbCarte() const {return nb;}

		bool estVide() const {
			return nb == 0;
		};

		const Carte& piocher();
	};

	class Plateau {
	private :
		const Carte** cartesVisible = nullptr;
		size_t nb = 0;
		size_t nbMax = 0;

	public:
		Plateau() = default;
		Plateau(const Plateau &pl); //Constructeur par recopie
		Plateau &operator=(const Plateau &pl); //Opérateur d'affectation

		~Plateau();

		void ajouter(const Carte& c);
		void retirer(const Carte& c);
		void afficher(std::ostream& os);
		size_t getNbCarte() const {
			return nb;
		}

		size_t getnbMax() const {
			return nbMax;
		}

		const Carte* getCarte(size_t i) const {
			return cartesVisible[i];
		}

		void redim(size_t n);
	};

	class Combinaison {
	private:
		const Carte* c1 = nullptr;
		const Carte* c2 = nullptr;
		const Carte* c3 = nullptr;

		static bool verifyCouleur(const Couleur a,const Couleur b, const Couleur c) {
			bool same = a == b && b == c && a == c;
			bool diff = a != b && a != c && b != c;
			return same || diff;
		}
		static bool verifyForme(const Forme a,const Forme b, const Forme c) {
			bool same = a == b && b == c && a == c;
			bool diff = a != b && a != c && b != c;
			return same || diff;
		}
		static bool verifyNombre(const Nombre a,const Nombre b, const Nombre c) {
			bool same = a == b && b == c && a == c;
			bool diff = a != b && a != c && b != c;
			return same || diff;
		}
		static bool verifyRemplissage(const Remplissage a,const Remplissage b, const Remplissage c) {
			bool same = a == b && b == c && a == c;
			bool diff = a != b && a != c && b != c;
			return same || diff;
		}

	public:
		Combinaison(const Carte& a, const Carte& b, const Carte& c) : c1(&a), c2(&b), c3(&c) {}
		~Combinaison() = default;
		Combinaison(const Combinaison &cb) = default; //Constructeur par recopie
		Combinaison &operator=(const Combinaison &cb) = default; //Opérateur d'affectation

		const Carte& getCarte1() const;
		const Carte& getCarte2() const;
		const Carte& getCarte3() const;

		bool estUnSET();
	};

	class Controleur {
	private:
		Jeu jeu;
		Plateau plateau;
		Pioche* pioche = nullptr;
	public:
		Controleur();
		~Controleur() {
			delete pioche;
		}

		Controleur(const Controleur &con) = delete;
		Controleur &operator=(const Controleur &con) = delete;

		const Plateau& getPlateau() const {
			return plateau;
		}

		void distribuer();
	};


	ostream& operator<<(ostream& f, const Plateau& pl);
	ostream& operator<<(ostream& f, const Combinaison& pl);

}

