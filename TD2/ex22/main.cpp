#include "set.h"
using namespace Set;

int main() {
	try {

		printCouleurs();
		printNombres();
		printFormes();
		printRemplissages();
	}
	catch (SetException& e) {
		std::cout << e.getInfo() << "\n";
	}

	Carte* tab[10] ;
	tab[3] = new Carte(Couleur::rouge, Nombre::deux, Forme::losange, Remplissage::plein);
	Carte** tabdyn = new Carte*[10];

	Jeu monJeu, monDeuximeJeu;
	
	system("pause");
	return 0;
}