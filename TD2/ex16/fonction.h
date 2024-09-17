//
// Created by andre on 17/09/2024.
//

#pragma once
#include <iostream>
using namespace std;

struct personne {
    char nom[30];
    unsigned int age;

};

void raz(personne& p);
void afficher_struct(personne& p);
void affiche_tab(const personne* p, size_t tab_size);
void init_struct(personne& p, const char* nom, unsigned int age);
void copy_struct(personne& dest, const personne& source);
void copy_tab(personne* dest, const personne* source, size_t tab_size);