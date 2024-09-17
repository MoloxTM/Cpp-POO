//
// Created by andre on 17/09/2024.
//
#include <iostream>
#include "fonction.h"
using namespace std;

int main() {
    cout << "Verif inverse adresse :\n";

    int a = 14;
    int b = 3;

    cout<<"Passage par adresse | a :"<<a<<" b :"<<b<<endl;
    inverse(&a, &b);
    cout<<"Résultat par adresse | a :"<<a<<" b :"<<b<<endl;
    cout<<"Passage par reférence | a :"<<a<<" b :"<<b<<endl;
    inverse(a, b);
    cout<<"Résultat par référence | a :"<<a<<" b :"<<b<<endl;

    return 0;
}