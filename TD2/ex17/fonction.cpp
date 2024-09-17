//
// Created by andre on 17/09/2024.
//

#include "fonction.h"
void raz(personne &p) {
    p.age = 0;
    p.name = "";
}

void afficher_struct(const personne& p) {
    cout<<"Age : "<<p.age<<" Nom : "<<p.name<<endl;
}

void affiche_tab(const personne *p, size_t tab_size) {
    cout<<"Tab : ";
    for (size_t i = 0; i < tab_size; i++) {
        afficher_struct(*p++);
    }
}

void init_struct(personne &p, const string& nom, unsigned int age) {
    p.age = age;
    p.name = nom;
}

void copy_struct(personne& dest, const personne& source) {
    dest = source;
}

void copy_tab(personne *dest, const personne *source, size_t tab_size) {
    for (size_t i = 0; i < tab_size; i++) {
        dest[i] = source[i];
    }
}





