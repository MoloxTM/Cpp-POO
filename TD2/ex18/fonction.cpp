//
// Created by andre on 17/09/2024.
//

#include "fonction.h"
#include <iostream>


compte& find(compte* tab, const string& id, size_t tab_size) {
    for (size_t i = 0; i < tab_size; i++) {
        if(tab[i].id == id) {
            return tab[i];
        }
    }
}

int& operation(compte* tab, const string& id) {
    size_t taille = sizeof(tab) / sizeof(tab[0]);
    compte& c = find(tab, id, taille);
    return  c.solde;
}

void essai_compte(){
    compte tab[4]={ {"courant", 0},{"codevi", 1500 },
    {"epargne", 200 }, { "cel", 300 } };
    operation(tab,"courant")=100;
    operation(tab,"codevi")+=100;
    operation(tab,"cel")-=50;
    for(int i=0; i<4; i++) cout<<tab[i].id<<" : "<<tab[i].solde<<"\n";
}

