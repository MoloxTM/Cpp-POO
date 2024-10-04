#include "set.h"
using namespace Set;

// Le passage de parametre permet ici de  tester si
// le constructeur de recopie est bien des-activé :

void _fonction_test_recopie_Jeu(Jeu _un_jeu_transmis_par_valeur_donc_recopie) {
    return;
}

void _fonction_conversion_implicite_Jeu_en_Pioche(Pioche _une_pioche)
{
    return;
}

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

    // return 0; // A commenter pour montrer Exercice 22, question 2

    // Exercice 22, question 2, Est-il possible de définir :
    // (a) un tableau contenant des objets Carte sans initialisateur ?
    // (b) un tableau contenant des pointeurs d'objets Carte sans initialisateur ?

    // Exercice 22, question 2, reponse (a) :
    // La classe Carte ne disposant pas de constructeur sans argument,
    // il n'est pas possible de définir un tableau d'objets Carte
    // ou d'utiliser l'opérateur new[] pour allouer dynamiquement un tableau d'objets Carte
    // sans fournir d'initialisateur.
    // Pourquoi ? Rappel cours "Allocation dynamique en C++", Slide 6
    // Instances de classes : le constructeur de ces classes sera automatiquement
    // appelé lors de leur initialisation. Or celui que nous avons defini a besoin de 4 valeurs.

    // Les objets Carte doivent être initialisés en faisant appel à l'unique constructeur
    // disponible :
    // Carte(Couleur c, Nombre v, Forme f, Remplissage r) :couleur(c), nombre(v), forme(f), remplissage(r) {};
    // Donc, il est possible de faire (allocation dynamique zone du tas, heap) :
    cout << "\n\n\n";
    cout << "----------------------------------" << "\n";
    cout << "Debut demo Exercice 22, question 2, reponse (a)" << "\n";
    Carte* _pt_carte = new Carte(Couleur::vert, Nombre::deux, Forme::ovale, Remplissage::vide);
    cout << *_pt_carte << "\t la carte \n";
    cout << "\n\n";
    // Mais aussi si plusieurs cartes :
    Carte _t_carte[2] = {
        Carte(Couleur::rouge, Nombre::un, Forme::vague, Remplissage::plein),
        Carte(Couleur::mauve, Nombre::trois, Forme::losange, Remplissage::hachure) };

    // Pour visualiser le contenu du tableau _t_carte
    for (auto i = 0; i < 2; i++) cout << _t_carte[i] << " carte case  " << i << "\n";

    // c'est-a-dire que :
    // allouer dynamiquement un tableau d'objets Carte est POSSIBLE en fournissant
    // TOUS les initialisateurs.
    // MAIS, lorsque le nombre d'initialisateurs requis n'est PAS CONNU,
    // cette opération n'est pas possible.

    // Exercice 22, question 2, reponse (b) :
    // Il est tout à fait possible de créer des tableaux de pointeurs d'objets Carte.
    // Car un pointeur n'a pas besoin d'être initialisé, donc on peut ecrire :
    cout << "\n\n\n";
    cout << "----------------------------------" << "\n";
    cout << "Debut demo Exercice 22, question 2, reponse (b)" << "\n";
    Carte* _tab[10]; // tableau de 10 pointeurs, note : warning C4101: '_tab' : variable locale non référencée
    _tab[3] = new Carte(Couleur::rouge, Nombre::deux, Forme::ovale, Remplissage::vide);
    cout << _tab[3] << " \taffiche la valeur du pointeur dans _tab[3], tableau de pointeurs de taille FIXE \n"; // affiche la valeur du pointeur
    cout << *_tab[3] << " \t\taffiche la carte pointee avec *_tab[3] \n"; // affiche la carte
    cout << "\nICI\n";
    cout << "\n\n\n";

    Carte** _tabdyn = new Carte * [10];
    // _tabdyn est un tableau alloué dynamiquement de 10 pointeurs sur des Cartes.
    //
    // Vous remarquerez que les cellules du tableau de pointeurs peut évidemment contenir
    // l'adresse d'un objet Carte qui aura été créé (dynamiquement ou non) par la suite.

    // Un exemple de création dynamique de carte APRES creation du tableau, voir ligne :
    _tabdyn[3] = new Carte(Couleur::vert, Nombre::deux, Forme::vague, Remplissage::hachure);

    cout << _tabdyn[3] << " \taffiche la valeur du pointeur dans _tabdyn[3], tableau de pointeurs alloue dynamiquement\n"; // affiche la valeur du pointeur
    cout << *_tabdyn[3] << " \t\taffiche la carte pointee par _tabdyn[3]\n"; // affiche la carte
    cout << "\nLA LA LA\n";


    // -------------------------------------------------------------
    // Exercice 22, question 3 : Quelle association lie les classes Carte et Jeu ?
    // L'association qui lie les classes Carte et Jeu est une composition de Jeu vers Carte :
    // la classe Carte est composée par la classe Jeu; la classe Jeu compose la classe Carte.
    // En effet, c'est l'objet Jeu qui va gérer le cycle de vie des objets Carte.
    // Cette composition à une multiplicité de 81 du côté de Carte.
    // -------------------------------------------------------------

    // -------------------------------------------------------------
    // Exercice 22, question 4 : Quel est l'intérêt d'avoir utilisé un attribut
    // de type const Carte * [81] plutôt que Carte * [81] ?

    // Reponse : Une fois la carte créée (dynamiquement),
    // il ne sera plus possible de la modifier par erreur.

    // return 0 ; // A commenter pour montrer Exercice 22, question 5

    // -------------------------------------------------------------
    // Exercice 22, question 5, voir mes commentaires dans set.h
    // ajouter/enlever le "delete" pour montrer
    cout << "\n\n\n";
    cout << "----------------------------------" << "\n";
    cout << "Debut demo Exercice 22, question 5, la class Jeu" << "\n";
    Jeu _Monjeu_a_moi, _mon_deuxieme_jeu_TEST_recopie_et_Affectation;
    cout << "\n";
    cout << "Combien de carte ? " << _Monjeu_a_moi.getNbCarte() << "\n";
    cout << "\n";
    cout << "La carte 31 : " << _Monjeu_a_moi.getCarte(31) << "\n";

    // Pour le constructeur de recopie de la class Jeu,
    // test pour voir s'il est bien desactivé (erreur de compilation) :

    // error C2280 : 'Set::Jeu::Jeu(const Set::Jeu &)' :
    // tentative de référencement d'une fonction supprimée
    // _fonction_test_recopie_Jeu(_Monjeu_a_moi);

    // pour l'operateur d'affectaion de la class Jeu,
    // test pour voir s'il est bien desactivé (erreur de compilation) :

    // error C2280: 'Set::Jeu &Set::Jeu::operator =(const Set::Jeu &)' :
    // tentative de référencement d'une fonction supprimée
    // _mon_deuxieme_jeu_TEST_recopie_et_Affectation = _Monjeu_a_moi;
    cout << "\n";
    // TEST  de
    // class SetException
    try {
        cout << "TEST de l'utilisation de class SetException : "
            << _Monjeu_a_moi.getCarte(127) << "\n";
    }
    catch (SetException& e) {
        std::cout << e.getInfo()
            << " --- Fin de essai exception avec _Monjeu_a_moi.getCarte(127) \n";
    }

    cout << "\n";
    //return 0 ; // A commenter pour montrer après Exercice 22 question 7

    // -------------------------------------------------------------
    // Exercice 22, question 6 : Quelle association lie les classes Carte et Pioche ?

    // Reponse :
    // L'association qui lie les classes Carte et Pioche est une agrégation de Pioche
    // vers Carte :
    // la classe Pioche agrège la classe Carte avec une valeur de multiplicité*
    // du côté Carte et a priori une valeur de multiplicité de 1 du côté Pioche
    // (si on considère qu'une carte ne peut être que dans une seule pioche à la fois).
    // En effet, bien qu'un objet Pioche est composé d'objets Carte,
    // il n'est pas responsable de leur cycle de vie.

    // -------------------------------------------------------------
    // Exercice 22, question 7 :
    cout << "\n\n\n";
    cout << "----------------------------------" << "\n";
    cout << "Debut demo Exercice 22, question 7, la class Pioche" << "\n";
    // Rappel contexte pour ici de la déclaration de l'objet "_Monjeu_a_moi"
    // Jeu _Monjeu_a_moi;
    //
    // Exemple et explication conversion implicite :
    // SANS le mot clef "explicit" devant la declaration de
    // Pioche(const Jeu& j) dans la class Pioche (voir set.h), ceci est possible
    //
    // Jouer avec le code, commenter/decommenter, explicit dans le set.h
    // cout << "Conversion implicite sans le mot clef explicit " << "\n";
    //  _fonction_conversion_implicite_Jeu_en_Pioche(_Monjeu_a_moi);

    //
    // Car il y a appel IMPLICITE de Pioche(const Jeu& j)
    //
    // Le compilateur a créé un objet temporaire "Pioche"
    // à partir du jeu "j" par appel du constructeur "Pioche(const Jeu& j)" qui joue ici le rôle
    // de "convertisseur", et a appliqué ensuite la fonction
    // _fonction_conversion_implicite_Jeu_en_Pioche sur cet objet temporaire…
    // Ça peut parfois être déroutant, et même dans des cas plus complexes générer
    // des erreurs TRES surprenantes.
    //
    // MAIS si on ajoute "explicit" devant la declaration, on a l'erreur :
    // error C2664: 'void _fonction_conversion_implicite_Jeu_en_Pioche(Set::Pioche)' :
    // impossible de convertir l'argument 1 de 'Set::Jeu' en 'Set::Pioche'
    // Aucun opérateur de conversion définie par l'utilisateur disponible qui puisse effectuer cette conversion,
    // ou l'opérateur ne peut pas être appelé

    // return 0;
    //
    // Jouer avec le code, commenter/decommenter
    // Exemple et explication initialisation par copie :
    //
    // cout << "Initialisation par copie sans le mot clef explicit " << "\n";
    //Pioche _inter_ma_pioche = _Monjeu_a_moi; // INTERDIT AVEC EXPLICIT
    Pioche _inter_ma_pioche(_Monjeu_a_moi); // Appel explicite au constructeur -> OK

    // initialisation par copie interdite si on ajoute "explicit" et on a l'erreur :
    // error C2440: 'initialisation' : impossible de convertir de 'Set::Jeu' en 'Set::Pioche'
    // Aucun opérateur de conversion définie par l'utilisateur disponible qui puisse effectuer cette conversion,
    // ou l'opérateur ne peut pas être appelé

    // Exercice 22, question 7.
    // tirage d'une Carte
    Pioche _ma_pioche(_Monjeu_a_moi); // ici c'est propre, c'est la seule façon
    // creer une pioche à partir de Jeu qui est souhaitable
    // Appel du constructeur de Pioche avec un Jeu

    // ICI _ref_une_carte_tiree est une ref d'une carte, voir Piocher.
    const Carte&  _ref_une_carte_tiree = _ma_pioche.piocher();

    cout << _ref_une_carte_tiree << "\t la carte que l'on vient de tirer \n";
    cout << "\tEst-ce que la pioche est vide ? " << _ma_pioche.estVide() << "\n";
    cout << "\tCombien de cartes restent dans la pioche " << _ma_pioche.getNbCarte() << "\n";

    // return 0;

    // -------------------------------------------------------------
    // Exercice 22, question 8, réponse  :
    // L'association qui lie les classes Carte et Plateau
    // est une agrégation de Plateau vers Carte :
    // la classe Plateau agrège la classe Carte avec une valeur de multiplicité 12..*
    // du côté Carte et a priori une valeur de multiplicité de 1 du côté Plateau
    // (si on considère qu'une carte ne peut être que dans une seule pioche à la fois).
    // En effet, bien qu'un objet Plateau est composé d'objets Carte,
    // il n'est pas responsable de leur cycle de vie.

    // -------------------------------------------------------------
    // Exercice 22, question 9, la class Plateau
    cout << "\n\n\n";
    cout << "----------------------------------" << "\n";
    cout << "Debut demo Exercice 22, question 9, la class Plateau " << "\n";
    cout << "Rappel, dans cette demo on a deja tire une carte c'est _une_carte_tiree  " << "\n";
    cout << "\n";
    // La class Plateau est un agrégat et Carte est la classe aggrégée
    Plateau _mon_plateau; // Constructeur Plateau() = default;
    // const Carte** cartes = nullptr; // initialement vide, c'est propre
    // size_t nbMax = 0; // ATTENTION, l'usage du constructeur fait donc que nbMax = 0
    // size_t nb = 0; // idem pour nb
    _mon_plateau.ajouter(_ref_une_carte_tiree);
    cout << "Nombre de carte : " << _mon_plateau.getNbCarte() << "\n";
    cout << "Le plateau est : \n" << _mon_plateau << "\n";

    cout << "On tire d'autres cartes de la pioche \n";
    for (auto i = 0; i < 11; i++)
    {
        const Carte & _une_autre_carte_tiree = _ma_pioche.piocher();
        cout << _une_autre_carte_tiree << "\n";
        _mon_plateau.ajouter(_une_autre_carte_tiree);
        // MAIS plus propre avec :
        // _mon_plateau.ajouter(_ma_pioche.piocher());
    }
    // return 0;
    cout << "\n";
    cout << "Le plateau avec 12 cartes : \n" << _mon_plateau << "\n";
    cout << "Nombre de carte : " << _mon_plateau.getNbCarte() << "\n";
    cout << "Nombre max de carte : " << _mon_plateau.getnbMax() << "\n";

    _mon_plateau.retirer(_ref_une_carte_tiree);
    cout << "Le plateau avec 11 cartes : \n" << _mon_plateau << "\n";
    cout << "Nombre de carte : " << _mon_plateau.getNbCarte() << "\n";
    cout << "Nombre max de carte : " << _mon_plateau.getnbMax() << "\n";

    // DONC pour vider le plateau, il suffit de retirer les cartes du plateau ...

    // return 0;
}