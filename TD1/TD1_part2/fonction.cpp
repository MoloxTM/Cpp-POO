#include "fonction.h"

void exercice_surcharge(){
    int i=3,j=15;
    float x=3.14159f ,y=1.414f;
    char c='A';
    double z=3.14159265;
    fct(i); //appel 1
    fct(x); //appel 2
    fct(i,y); //appel 3
    fct(x,j); //appel 4
    fct(static_cast<int>(c)); //appel 5 on convertit explicitement le char en int
    fct(i,static_cast<float>(j)); //appel 6 deux int en param mais aucune def corresond à cet appel
    fct(i,static_cast<float>(c)); //appel 7 un int et un char en param mais aucune d
    fct(i,static_cast<float>(z)); //appel 8
    fct(static_cast<int>(z),static_cast<float>(z)); //appel 9
}
