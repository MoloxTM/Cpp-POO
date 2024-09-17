//
// Created by andre on 17/09/2024.
//

//double& d1=36; // On déclare une variable de référence, on doit fournir une adresse et non une valeur
const double& d1=36; // Correction possible car on ne pourra pas changer la valeur de la ref
double d2=36;
double& ref = d2;
ref = 4; // On a déclaré une variable de référence au dessus et là on lui passe une valeur et nn une adresse
const double d3=36;
const double& d4=36;
const double& d5=d2;
d5=21; //Erreur, avec une référence const, on ne peut pas modifier la donnée reférence même si cette donnée n'est pas const
const double& d6=d3;
//double& ref2=d6; //ref2 n'est pas du même type que d6, il ne peut pas recevoir une autre adresse que de type double
double& ref2 = const_cast<double&>(d6);
int i = 4;
double& d7=i; //Incohérence au niveau des types
const double& d8=i;
d8=3; //On essai de changer la valeur alors qu'on a un const
