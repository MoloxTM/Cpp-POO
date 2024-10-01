#include "set.h"
#include <cstdlib>  // pour std::rand
#include <ctime>    // pour std::time

namespace Set {
	
	std::initializer_list<Couleur> Couleurs = { Couleur::rouge, Couleur::mauve, Couleur::vert };
	std::initializer_list<Nombre> Nombres = { Nombre::un, Nombre::deux, Nombre::trois };
	std::initializer_list<Forme> Formes = { Forme::ovale, Forme::vague, Forme::losange };
	std::initializer_list<Remplissage> Remplissages = { Remplissage::plein, Remplissage::vide, Remplissage::hachure };

	string toString(Couleur c) {
		switch (c) { 
		case Couleur::rouge: return "R";
		case Couleur::mauve: return "M";
		case Couleur::vert: return "V";
		default: throw SetException("Couleur inconnue");
		}
	}

	string toString(Nombre v) {
		switch (v) {
		case Nombre::un: return "1";
		case Nombre::deux: return "2";
		case Nombre::trois: return "3";
		default: throw SetException("Nombre inconnue");
		}
	}

	string toString(Forme f) {
		switch (f) {
		case Forme::ovale: return "O";
		case Forme::vague: return "~";
		case Forme::losange: return "\004";
		default: throw SetException("Forme inconnue");
		}
	}

	string toString(Remplissage r) {
		switch (r) {
		case Remplissage::plein: return "P";
		case Remplissage::vide: return "_";
		case Remplissage::hachure: return "H";
		default: throw SetException("Remplissage inconnu");
		}
	}

	std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
	std::ostream& operator<<(std::ostream& f, Nombre v) {	f << toString(v); return f; }
	std::ostream& operator<<(std::ostream& f, Forme x) { f << toString(x);  return f; }
	std::ostream& operator<<(std::ostream& f, Remplissage r) { f << toString(r); return f; }

	void printCouleurs(std::ostream& f) {
		for (auto c : Couleurs) f << c << " ";
		f << "\n";
	}

	void printNombres(std::ostream& f) {
		for (auto v : Nombres) f << v << " ";
		f << "\n";
	}

	void printFormes(std::ostream& f) {
		for (auto x : Formes) f << x << " ";
		f << "\n";
	}

	void printRemplissages(std::ostream& f) {
		for (auto r : Remplissages) f << r << " ";
		f << "\n";
	}

	ostream& operator<<(ostream& f, const Carte& c) {
		f << "(" << c.getNombre() << "," << c.getCouleur() << "," << c.getForme() << "," << c.getRemplissage() << ")";
		return f;
	}

	Jeu::Jeu() {
		cout<<"\tEntre dans le Constructeur sans argumentde jeu\n"<<endl;
		size_t i = 0;
		for (auto c : Couleurs) {
			for (auto n : Nombres) {
				for (auto f : Formes) {
					for (auto r : Remplissages) {
						cartes[i] = new Carte(c, n, f, r);
						i++;
					}
				}
			}
		}
		cout<<"\tSortie du Constructeur sans argumentde jeu\n"<<endl;
	}

	Jeu::~Jeu() {
		cout<<"\tEntre dans le destructeur de Jeu\n";
		for (size_t i = 0; i < nbCarte; i++) {
			delete cartes[i];
		}
		cout<<"\tSortie du destructeur de Jeu\n";
	}


	Pioche::Pioche(const Jeu &jeu) : cartes(new const Carte *[jeu.getNbCarte()]), nb(jeu.getNbCarte()) {

		for (size_t i = 0; i < nb; ++i) {
			cartes[i] = &jeu.getCarte(i);
		}
		// Initialiser la génération aléatoire
		std::srand(std::time(0));
	}

	Pioche::~Pioche() {
		delete[] cartes;
	}


	const Carte &Pioche::piocher() {
		if(nb == 0) throw SetException("Pioche vide");
		size_t x = rand() % nb;
		const Carte* c = cartes[x];
		for (size_t i = x + 1; i < nb; ++i) {
			cartes[i - 1] = cartes[i];
		}

		nb--;
		return *c;
	}

	Plateau::~Plateau() {
		delete[] cartesVisible;

	}

	Plateau::Plateau(const Plateau &pl) : cartesVisible(new const Carte *[pl.nb]), nb(pl.nb), nbMax(pl.nbMax) {
		for (size_t i = 0; i < nb; ++i) {
			cartesVisible[i] = pl.cartesVisible[i];
		}
	}

	Plateau &Plateau::operator=(const Plateau &p) {
		if(this != &p) { //Evite de recopier un objet qui est lui même, genre a = a
			if(p.nb > nbMax) {
				const Carte** newTab = new const Carte *[p.nb];
				for (size_t i = 0; i < nb; i++) {
					newTab[i] = p.cartesVisible[i];;
				}
				auto old = cartesVisible;
				cartesVisible = newTab;
				nb = nbMax = p.nbMax;
				delete[] old;
			} else {
				//Il n'y a pas assez de place
				for (size_t i = 0; i < nb; i++) {
					cartesVisible[i] = p.cartesVisible[i];
					nb = p.nb;
				}
			}
		}
		return *this;
	}


	void Plateau::ajouter(const Carte &c) {
		if(nb == nbMax) {
			redim((nbMax + 1) * 2);
		}
		cartesVisible[nb++] = &c;
	}

	void Plateau::retirer(const Carte& c) {
		size_t i = 0;
		while (i < nb && cartesVisible[i] != &c) {
			i++;
		}
		if(i == nb) throw SetException("Carte inexistante");

		while(i < nb) {
			cartesVisible[i-1] = cartesVisible[i];
			i++;
		}
		nb--;
	}

	void Plateau::afficher(ostream& os) {
		os<<"Cartes présentes sur le tableau:\n"<<endl;
		for(size_t i = 0; i < nb; i++) {
			if (i % 4 == 0) os << "\n";
			os<<*cartesVisible[i]<<" ";
		}
		os<<"\n";
	}

	void Plateau::redim(size_t n) {
		const Carte** nouveauTableau = new const Carte*[n];
		std::copy(cartesVisible	, cartesVisible + nb, nouveauTableau);
		for(size_t i = 0; i < nb; i++) {
			nouveauTableau[i] = cartesVisible[i];
		}
		auto old = cartesVisible;;
		cartesVisible = nouveauTableau;
		nbMax = n;
		delete [] old;
	}


}