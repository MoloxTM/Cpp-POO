#include <iostream>

using namespace std;

int main()
{

    double* pt0=0; // c'est mieux d'utilise null_ptr
    double* pt1=4096; //on demande un pt double mais on lui donne un int comme valeur + cc'est une valeur m�moire donc chelou de faire �a
    double* pt2=(double*)4096; //on essai d'acc�der � une adresse m�moire qu'on ne doit pas acc�der
    void* pt3=pt1;
    pt1=pt3;
    pt1=(double*)pt3;
    double d1=36;
    const double d2=36;
    double* pt4=&d1;
    const double* pt5=&d1; // on ne pourra pas modifier ce qui est point�
    *pt4=2.1;
    *pt5=2.1;   //on a modifi� la valeur du pt5 alors que c'ets une constante
    pt4=&d2;    // on fait pointer un pt sur un constant, il y a risque de modification de la valeur de la constante
    pt5=&d2;
    double* const pt6=&d1;
    pt6=&d1;
    *pt6=2.78;
    double* const pt6b=&d2;
    const double* const pt7=&d1;
    pt7=&d1;
    *pt7=2.78;
    double const* pt8=&d1;
    pt8=&d2;
    pt8=&d1;
    *pt8=3.14;

    return 0;
}
