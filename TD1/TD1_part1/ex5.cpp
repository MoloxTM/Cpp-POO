#include <iostream>
#include <string>

using namespace std;

const float pi = 3.14159;

void exercice5() {
    cout<<"Donnez le rayon entier d'un cercle\n";
    int r;
    cin>>r;
    int p;
    p=2*pi*r;
    int s;
    s = pi*r*r;
    cout<<"Le cercle est de rayon "<<r<<" ";
    cout<<"a un perimetre de "<<p<<" et une surface de "<<s;
}

