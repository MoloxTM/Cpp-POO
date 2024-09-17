//
// Created by andre on 17/09/2024.
//

#include "fonction.h"
void raz(personne &p) {
    p.age = 0;
    p.nom[0] = '\0';
}

void afficher_struct(const personne& p) {
    cout<<"Age : "<<p.age<<" Nom : "<<p.nom;
}

void affiche_tab(const personne *p, size_t tab_size) {
    cout<<"Tab : ";
    for (size_t i = 0; i < tab_size; i++) {
        afficher_struct(*p++);
    }
}

void init_struct(personne &p, const char *nom, unsigned int age) {
    p.age = age;
    char* pt = p.nom;
    while (*nom) {
        cout<<"Contenu de nom :"<<*nom;
        *pt = *nom;
        ++nom;
        ++pt;
    }
    *pt = '\0';
}

void copy_struct(personne& p, const personne& q) {
    p = q;
}

void copy_tab(personne *p, const personne *q, size_t tab_size) {
    for (size_t i = 0; i < tab_size; i++) {
        p[i] = q[i];
    }
}





