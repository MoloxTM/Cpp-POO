//
// Created by andre on 17/09/2024.
//
#pragma once
#include <iostream>

struct point {
    int x = 0, y = 0, z = 0;

    void init(int x, int y, int z);
};

void init(point& p, int x = 0, int y = 0, int z = 0);
void essai_init();
void affiche(point &p);


